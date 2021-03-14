
#include <rclcpp/rclcpp.hpp>

#include <sl/Camera.hpp>
#include "aruco.hpp"
#include <opencv2/opencv.hpp>
#include "messages/msg/zed_position.hpp"


//using namespace sl;
//using namespace std;

int main(int argc, char **argv) {
    rclcpp::init(argc,argv);
    rclcpp::Node::SharedPtr nodeHandle = rclcpp::Node::make_shared("zed_tracking");

    RCLCPP_INFO(nodeHandle->get_logger(),"Starting zed_tracking");

    auto zedPositionPublisher=nodeHandle->create_publisher<messages::msg::ZedPosition>("zed_position",1);
    messages::msg::ZedPosition zedPosition;

    // Create a ZED camera object
    sl::Camera zed;

    // Set configuration parameters
    sl::InitParameters init_params;
//    init_params.camera_resolution = sl::RESOLUTION::HD720;
    init_params.camera_resolution = sl::RESOLUTION::VGA;
    init_params.coordinate_units = sl::UNIT::METER;
    init_params.coordinate_system = sl::COORDINATE_SYSTEM::RIGHT_HANDED_Y_UP;
    init_params.sensors_required = false;

    float deltaX = 0;
    float deltaY = 0;
    float deltaZ = 0;
    float zedX = 0;
    float zedY = 0;
    float zedZ = 0;

    // Open the camera
    sl::ERROR_CODE err = zed.open(init_params);
    if (err != sl::ERROR_CODE::SUCCESS) {
	std::cout << "Error, unable to open ZED camera: " << err << "\n";
        zed.close();
        return 1; // Quit if an error occurred
    }

    auto cameraInfo = zed.getCameraInformation();
    sl::Resolution image_size = cameraInfo.camera_resolution;
    sl::Mat image_zed(image_size, sl::MAT_TYPE::U8_C4);
    cv::Mat image_ocv = cv::Mat(image_zed.getHeight(), image_zed.getWidth(), CV_8UC4, image_zed.getPtr<sl::uchar1>(sl::MEM::CPU));
    cv::Mat image_ocv_rgb;

    auto calibInfo = cameraInfo.calibration_parameters.left_cam;
    cv::Matx33d camera_matrix = cv::Matx33d::eye();
    camera_matrix(0, 0) = calibInfo.fx;
    camera_matrix(1, 1) = calibInfo.fy;
    camera_matrix(0, 2) = calibInfo.cx;
    camera_matrix(1, 2) = calibInfo.cy;

    cv::Matx<float, 4, 1> dist_coeffs = cv::Vec4f::zeros();

    float actual_marker_size_meters = 0.16f; // real marker size in meters
    auto dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_100);

    std::cout << "Make sure the ArUco marker is a 6x6 (100), measuring " << actual_marker_size_meters * 1000 << " mm" << std::endl;

    sl::Transform pose;
    sl::Pose zed_pose;
    std::vector<cv::Vec3d> rvecs, tvecs;
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f> > corners;
    std::string zed_position_txt;
    std::string zed_rotation_txt;
    std::string aruco_position_txt;

    bool can_reset = false;

    sl::PositionalTrackingParameters tracking_params;
    tracking_params.enable_imu_fusion = false; // for this sample, IMU (of ZED-M) is disable, we use the gravity given by the marker.
    tracking_params.enable_area_memory = true;
    auto returned_state = zed.enablePositionalTracking(tracking_params);
    if (returned_state != sl::ERROR_CODE::SUCCESS) {
        zed.close();
        return EXIT_FAILURE;
    }
    sl::POSITIONAL_TRACKING_STATE tracking_state;

    // Loop until 'q' is pressed
    while (rclcpp::ok()) {
        if (zed.grab() == sl::ERROR_CODE::SUCCESS) {
            // Retrieve the left image
            zed.retrieveImage(image_zed, sl::VIEW::LEFT, sl::MEM::CPU, image_size);

            // convert to RGB
            cv::cvtColor(image_ocv, image_ocv_rgb, cv::COLOR_RGBA2RGB);
            // detect marker
            cv::aruco::detectMarkers(image_ocv_rgb, dictionary, corners, ids);

            // get actual ZED position
            tracking_state = zed.getPosition(zed_pose, sl::REFERENCE_FRAME::WORLD);
	    if (tracking_state == sl::POSITIONAL_TRACKING_STATE::OK) {
	       zedX=zed_pose.pose_data.tx;
               zedY=zed_pose.pose_data.ty;	       
	       zedZ=zed_pose.pose_data.tz;
            // display ZED position
                zed_position_txt = "ZED  x: " + std::to_string(zed_pose.pose_data.tx) + "; y: " + std::to_string(zed_pose.pose_data.ty) + "; z: " + std::to_string(zed_pose.pose_data.tz);
                zed_rotation_txt = "ZED  a: " + std::to_string(zed_pose.getOrientation().ox) + "; b: " + std::to_string(zed_pose.getOrientation().oy) + "; c: " + std::to_string(zed_pose.getOrientation().oz);
	    }else{
		 zed_position_txt = "";
		 zed_rotation_txt = "";
	    }

            // if at least one marker detected
            if (ids.size() > 0) {
                cv::aruco::estimatePoseSingleMarkers(corners, actual_marker_size_meters, camera_matrix, dist_coeffs, rvecs, tvecs);
                pose.setTranslation(sl::float3(tvecs[0](0), tvecs[0](1), tvecs[0](2)));
                pose.setRotationVector(sl::float3(rvecs[0](0), rvecs[0](1), rvecs[0](2)));
                pose.inverse();
                can_reset = true;

		deltaX = pose.tx - zedX;
		deltaY = pose.ty - zedY;
		deltaZ = pose.tz - zedZ;

                aruco_position_txt = "Aruco x: " + std::to_string(pose.tx) + "; y: " + std::to_string(pose.ty) + "; z: " + std::to_string(pose.tz);

            } else{
		aruco_position_txt = "";    
                can_reset = false;
	    }

	    zedX += deltaX;
	    zedY += deltaY;
	    zedZ += deltaZ;

	    zedPosition.x=zedX;
	    zedPosition.y=zedY;
	    zedPosition.z=zedZ;

	    zedPositionPublisher->publish(zedPosition);

	    std::cout << "ZED: x:" << zedX << " y: " << zedY << " z:" << zedZ << "   " << aruco_position_txt << std::endl;

            //zed.resetPositionalTracking(pose);
        }
    }
    zed.close();
    return 0;

}

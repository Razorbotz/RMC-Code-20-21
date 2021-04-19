#include "Automation.hpp"

class Automation1 : public Automation{

    enum RobotState{LOCATE,GO_TO_DIG_SITE,DIG,HOME,DOCK,DUMP};
    RobotState robotState=GO_TO_DIG_SITE;
    Location destination;

    void automate(){
        if(robotState==LOCATE){
            changeSpeed(0.15,-0.15);
            if(position.arucoVisible==true){
                robotState=GO_TO_DIG_SITE;
                destination.x=-5;
                destination.z=2;
                changeSpeed(0,0);
            }
        }
        if(robotState==GO_TO_DIG_SITE){
            Quaternion quaternion;
            quaternion.x=position.ox;
            quaternion.y=position.oy;
            quaternion.z=position.oz;
            quaternion.w=position.ow;
            EulerAngles eulerAngles=ToEulerAngles(quaternion);
            double yawRadians=eulerAngles.roll;

            double facingUnitX=-sin(yawRadians);
            double facingUnitZ=cos(yawRadians);
            // RCLCPP_INFO(nodeHandle->get_logger(),"%f %f %f ",eulerAngles.roll,eulerAngles.pitch,eulerAngles.yaw);
            double directionX=destination.x-position.x;
            double directionZ=destination.z-position.z;

            double theta = acos((facingUnitX*directionX + facingUnitZ*directionZ)/(sqrt(directionX*directionX + directionZ*directionZ)))*180/M_PI;
            double yaw = yawRadians * 180/M_PI;
            double deltaYaw = theta-yaw;
            double yawTolerance=5;
        if(deltaYaw > yawTolerance){
            changeSpeed(-0.15,0.15);
        }else if (deltaYaw < yawTolerance){
            changeSpeed(0.15,-0.15);
        }else{
             changeSpeed(0.15 - 0.1*deltaYaw/yawTolerance,0.15 + 0.1*deltaYaw/yawTolerance);
        }
        std::cout << eulerAngles.roll*180/M_PI << ", " << eulerAngles.pitch*180/M_PI << ", " << eulerAngles.yaw*180/ M_PI << "   "
                  << "   \t" << position.x << "  " << position.y << "  " << position.z
                  << "   \t" << position.ox << "  " << position.oy << "  " << position.oz << "  " << position.ow
                  << "   \t" << facingUnitX << " " << facingUnitZ << "   " << yaw << " " << deltaYaw << " " << theta
                  << "   \t" << position.arucoVisible << std::endl;
        }else{
            changeSpeed(0,0);
        }
    }

};

#include <math.h>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/int8.hpp>
#include <std_msgs/msg/u_int8.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>

#include <messages/msg/button_state.hpp>
#include <messages/msg/hat_state.hpp>
#include <messages/msg/axis_state.hpp>
#include <messages/msg/key_state.hpp>
#include <messages/msg/zed_position.hpp>

//#define _USE_MATH_DEFINES
#include <cmath>

rclcpp::Node::SharedPtr nodeHandle;

float joystick1Roll=0;
float joystick1Pitch=0;
float joystick1Yaw=0;
float joystick1Throttle=1;

bool automationGo=false;

std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Float32_<std::allocator<void> >, std::allocator<void> > > driveLeftSpeedPublisher;
std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Float32_<std::allocator<void> >, std::allocator<void> > > driveRightSpeedPublisher;
std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Bool_<std::allocator<void> >, std::allocator<void> > > driveStatePublisher;

void updateSpeed(){
    
    std_msgs::msg::Float32 speedLeft;
    std_msgs::msg::Float32 speedRight;
    float maxSpeed = 0.4;
    
    //Linear transformation of cordinate planes
    speedLeft.data  = (joystick1Pitch + joystick1Roll);
    speedRight.data = (joystick1Pitch - joystick1Roll);
    
    //multiplied the output speed by the "throttle" value and a limiting precentage
    speedLeft.data  = speedLeft.data * maxSpeed;
    speedRight.data = speedRight.data * maxSpeed;
    
    RCLCPP_INFO(nodeHandle->get_logger(),"speed left=%f right=%f  pitch=%f roll=%f", speedLeft.data,  speedRight.data, joystick1Pitch, joystick1Roll);

    driveLeftSpeedPublisher->publish(speedLeft);
    driveRightSpeedPublisher->publish(speedRight);
}


void joystickAxisCallback(const messages::msg::AxisState::SharedPtr axisState){
    RCLCPP_INFO(nodeHandle->get_logger(),"Button %d %d %f", axisState->joystick, axisState->axis, axisState->state);
    float deadZone = 0.1;
    if(axisState->axis==0){
        joystick1Roll = -axisState->state;
        joystick1Roll = (fabs(joystick1Roll)<deadZone)? 0.0 : joystick1Roll;
	joystick1Roll = (joystick1Roll>0)?joystick1Roll-deadZone:joystick1Roll;
	joystick1Roll = (joystick1Roll<0)?joystick1Roll+deadZone:joystick1Roll;
        updateSpeed();
    }else if(axisState->axis==1){
        joystick1Pitch = axisState->state;
        joystick1Pitch = (fabs(joystick1Pitch)<deadZone)? 0.0 : joystick1Pitch;
	joystick1Pitch = (joystick1Pitch>0)?joystick1Pitch-deadZone:joystick1Pitch;
	joystick1Pitch = (joystick1Pitch<0)?joystick1Pitch+deadZone:joystick1Pitch;
        updateSpeed();
    }else if(axisState->axis==2){
        joystick1Yaw = axisState->state;
    }else if(axisState->axis==3){
        joystick1Throttle = axisState->state/2+0.5;
    }
}


void joystickButtonCallback(const messages::msg::ButtonState::SharedPtr buttonState){
    std::cout << "Button " << buttonState->joystick << " " << buttonState->button << " " << buttonState->state << std::endl;
    std_msgs::msg::Bool but7;
    std_msgs::msg::Bool but8;
    std_msgs::msg::Bool driveState;

    switch (buttonState->button) {

        case 0: //ESTOP
//            DO NOT USE!!!
            break;
        case 1: //toggles driving and digging
            break;
        case 2:
            break;
        case 3:
            if (buttonState->state) {
            }else{
            }
            break;
        case 4:
            if(buttonState->state) {
            }else {
            }
            break;
        case 5: 
            if(buttonState->state) {
            }else {
            }
            break;
        case 6: 
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
    }
}


void joystickHatCallback(const messages::msg::HatState::SharedPtr hatState){
    std::cout << "Hat " << hatState->joystick << " " << hatState->hat << " " << hatState->state << std::endl;
}

void keyCallback(const messages::msg::KeyState::SharedPtr keyState){
    std::cout << "Key " << keyState->key << " " << keyState->state << std::endl;

    if(keyState->key==115 && keyState->state==1){
        automationGo= !automationGo;
    }
}

struct Position{
    double x,y,z,ox,oy,oz,ow,arucoVisible;
};
Position position;
void zedPositionCallback(const messages::msg::ZedPosition::SharedPtr zedPosition){
    position.x=zedPosition->x;	
    position.y=zedPosition->y;	
    position.z=zedPosition->z;	
    position.ox=zedPosition->ox;	
    position.oy=zedPosition->oy;	
    position.oz=zedPosition->oz;	
    position.ow=zedPosition->ow;	
    position.arucoVisible=zedPosition->aruco_visible;	
}

float currentLeftSpeed=0;
float currentRightSpeed=0;
void changeSpeed(float left, float right){
    if(currentLeftSpeed==left && currentRightSpeed==right) return;
    currentLeftSpeed=left;
    currentRightSpeed=right;
    std_msgs::msg::Float32 speedLeft;
    std_msgs::msg::Float32 speedRight;
    speedLeft.data=left;
    speedRight.data=right;
    driveLeftSpeedPublisher->publish(speedLeft);
    driveRightSpeedPublisher->publish(speedRight);
}

struct Location{
    double x,z;
};

struct Quaternion {
    double w, x, y, z;
};

struct EulerAngles {
    double roll, pitch, yaw;
};

EulerAngles ToEulerAngles(Quaternion q) {
    EulerAngles angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    angles.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (q.w * q.y - q.z * q.x);
    if (std::abs(sinp) >= 1)
        angles.pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        angles.pitch = std::asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    angles.yaw = std::atan2(siny_cosp, cosy_cosp);

    return angles;
}


enum RobotState{LOCATE,GO_TO_DIG_SITE,DIG,HOME,DOCK,DUMP};
RobotState robotState=GO_TO_DIG_SITE;
Location destination;
void automate(){
    if(automationGo){
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
	    double deltaYaw= theta-yaw;
	    double yawTolerance=5;
	    if(deltaYaw > yawTolerance){
	        changeSpeed(-0.15,0.15);
	    }else if (deltaYaw < yawTolerance){
	        changeSpeed(0.15,-0.15);
          		 
            }else{
	        changeSpeed(0.15 - 0.1*deltaYaw/yawTolerance,0.15 + 0.1*deltaYaw/yawTolerance);
	    }
	    std::cout << eulerAngles.roll*180/M_PI << ", " << eulerAngles.pitch*180/M_PI << ", " << eulerAngles.yaw*180/M_PI << "   " 
		    << "   \t" << position.x << "  " << position.y << "  " << position.z 
//		    << "   \t" << position.ox << "  " << position.oy << "  " << position.oz << "  " << position.ow 
		    << "   \t" << facingUnitX << " " << facingUnitZ << "   " << yaw << " " << deltaYaw << " " << theta
		    << "   \t" << position.arucoVisible << std::endl;
	}
    }else{
        changeSpeed(0,0);
    }	
}




int main(int argc, char **argv){
    rclcpp::init(argc,argv);
    nodeHandle = rclcpp::Node::make_shared("logic");
    auto joystickAxisSubscriber= nodeHandle->create_subscription<messages::msg::AxisState>("joystick_axis",1,joystickAxisCallback);
    auto joystickButtonSubscriber= nodeHandle->create_subscription<messages::msg::ButtonState>("joystick_button",1,joystickButtonCallback);
    auto joystickHatSubscriber= nodeHandle->create_subscription<messages::msg::HatState>("joystick_hat",1,joystickHatCallback);
    auto keySubscriber= nodeHandle->create_subscription<messages::msg::KeyState>("key",1,keyCallback);
    auto zedPositionSubscriber= nodeHandle->create_subscription<messages::msg::ZedPosition>("zed_position",1,zedPositionCallback);
    
    driveLeftSpeedPublisher= nodeHandle->create_publisher<std_msgs::msg::Float32>("drive_left_speed",1);
    driveRightSpeedPublisher= nodeHandle->create_publisher<std_msgs::msg::Float32>("drive_right_speed",1);
    driveStatePublisher= nodeHandle->create_publisher<std_msgs::msg::Bool>("drive_state",1);

    rclcpp::Rate rate(20);
    //double increment=.01;
    //double joystickXPrevious=0;

    while(rclcpp::ok()){
	automate();
        rclcpp::spin_some(nodeHandle);
	rate.sleep();
    }
}

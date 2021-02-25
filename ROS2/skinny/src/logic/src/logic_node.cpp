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

rclcpp::Node::SharedPtr nodeHandle;

float joystick1Roll=0;
float joystick1Pitch=0;
float joystick1Yaw=0;
float joystick1Throttle=1;

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
    
    RCLCPP_INFO(nodeHandle->get_logger(),"speed %f %f", speedLeft.data,  speedRight.data);

    driveLeftSpeedPublisher->publish(speedLeft);
    driveRightSpeedPublisher->publish(speedRight);
}


void joystickAxisCallback(const messages::msg::AxisState::SharedPtr axisState){
    RCLCPP_INFO(nodeHandle->get_logger(),"Button %d %d %f", axisState->joystick, axisState->axis, axisState->state);
    float deadZone = 0.1;
    if(axisState->axis==0){
        joystick1Roll = -axisState->state;
        joystick1Roll = (fabs(joystick1Roll)<deadZone)? 0.0 : joystick1Roll;
	joystick1Roll = (joystick1Roll>0)?joystick1Roll-deadZone:joystick1Roll+deadZone;
        updateSpeed();
    }else if(axisState->axis==1){
        joystick1Pitch = axisState->state;
        joystick1Pitch = (fabs(joystick1Pitch)<deadZone)? 0.0 : joystick1Pitch;
	joystick1Pitch = (joystick1Pitch>0)?joystick1Pitch-deadZone:joystick1Pitch+deadZone;
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


int main(int argc, char **argv){
    rclcpp::init(argc,argv);
    nodeHandle = rclcpp::Node::make_shared("logic");
    auto joystickAxisSubscriber= nodeHandle->create_subscription<messages::msg::AxisState>("joystick_axis",1,joystickAxisCallback);
    auto joystickButtonSubscriber= nodeHandle->create_subscription<messages::msg::ButtonState>("joystick_button",1,joystickButtonCallback);
    auto joystickHatSubscriber= nodeHandle->create_subscription<messages::msg::HatState>("joystick_hat",1,joystickHatCallback);
    
    driveLeftSpeedPublisher= nodeHandle->create_publisher<std_msgs::msg::Float32>("drive_left_speed",1);
    driveRightSpeedPublisher= nodeHandle->create_publisher<std_msgs::msg::Float32>("drive_right_speed",1);
    driveStatePublisher= nodeHandle->create_publisher<std_msgs::msg::Bool>("drive_state",1);

    rclcpp::Rate rate(10);
    //double increment=.01;
    //double joystickXPrevious=0;
    while(rclcpp::ok()){
        rclcpp::spin_some(nodeHandle);
    }
}

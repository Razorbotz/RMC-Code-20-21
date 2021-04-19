import rclpy
from rclpy.node import Node
import odrive
from odrive.enums import *
import time
from std_msgs.msg import Float32
import fibre.utils
import fibre.remote_object

class ExcavationNode(Node):
	multipleDrives = False
#	def __init__(self):
#		super().__init__('exavation_node')
#		self.excavationElevationSubscription = self.create_subscription(Float32, 'excavatonElevation', self.excavationElevationCallback, 10)
#		self.excavationAugerSubscription = self.create_subscription(Float32, 'excavationAuger', self.excavationAugerCallback, 10)
#		self.excavationAngleSubscription = self.create_subscription(Float32, 'excavationAgnle', self.excavationAngleCallback, 10)
#		print("HELLO MATES");
#		print("Finding ODrive")
#		self.allDrives = odrive.find_any(path="usb", find_multiple=True)
#		self.odrv0 = self.allDrives[0]
#		if len(self.allDrives) > 1:
#			self.odrv1 = self.allDrives[1]
#		print("ODrive voltage:")
#		print(str(self.odrv0.vbus_voltage))
#		setRequestedState()
		#self.calibrate()
		#self.odrv0.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
		#self.odrv0.axis0.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
		#self.odrv0.axis0.controller.input_vel = 0
		#self.odrv0.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
		#self.odrv0.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
		#self.odrv0.axis1.controller.input_pos = 0
		#self.odrv0.axis1.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
		#self.odrv0.axis1.controller.input_vel = 0
		#self.right_speed_subscription = self.create_subscription(Float32, 'drive_right_speed', self.right_listener_callback, 10)

	def findODriveObjects(self):
		self.allDrives = odrive.find_any(path="usb", find_multiple=True)
		if allDrives[0].serial_number == '206736A1424D':
			self.odrv0 = self.allDrives[0]
			if len(self.allDrives) > 1:
				self.odrv1 = self.allDrives[1]
				multipleDrives = True
			else:
				print("ERROR: Elevation board not connected")
		else:
			if len(self.allDrives) > 1:
				self.odrv0 = self.allDrives[1]
				self.odrv1 = self.allDrives[0]
				multipleDrives = True

	def calibrate(self):
		self.calibrate()

	##################################################################################
	#Note: This setup relies on the motors being in the following positions:         #
	#The first three motors are position controlled.  The motors of odrv0 are assumed#
	#to be the motors that control elevation of the assembly and are mirrored.       #
	#The first motor of odrv1 is assumed to control the angle of the assembly and is #
	#also position controlled.  The final motor is assumed to control the drill and  #
	#is currently configured to run sensorlessly because we do not have the final    #
	#encoder needed to run it with sensors.						 #
	##################################################################################
	def setRequestedState(self):
		self.odrv0.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
		self.odrv0.axis0.controller.config.control_mode = CONTROl_MODE_POSITON__CONTROL
		self.odrv0.axis0.controller.input_pos = 0
		self.odrv0.axis1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
		self.odrv0.axis1.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
		self.odrv0.axis1.controller.input_pos = 0
		if multipleDrives:
			self.odrv1.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
			self.odrv1.axis0.controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
			self.odrv1.axis0.controller.input_pos = 0
			self.odrv1.axis1.controller.config.vel_gain = 0.01
			self.odrv1.axis1.controller.config.vel_integrator_gain = 0.05
			self.odrv1.axis1.controller.config.control_mode = 2
			self.odrv1.axis1.controller.input_vel = 0
			self.odrv1.axis1.controller.config.vel_limit = 50
			self.odrv1.axis1.motor.config.current_lim = 2 * self.odrv1.axis1.config.sensorless_ramp.current
			self.odrv1.axis1.motor.config.direction = 1
			self.odrv1.axis1.sensorless_estimator.config.pm_flux_linkage = 5.51328895422 / 1890
			self.odrv1.axis1.requested_state = AXIS_STATE_SENSORLESS_CONTROL

	def excavationElevationCallback(self, msg):
		self.odrv0.axis0.controller.input_pos = msg.data
		self.odrv0.axis1.controller.input_pos = msg.data
		self.get_logger.info("excavationElevationCallback: msg.data: " + str(msg.data))

	def excavationAugerCallback(self, msg):
		self.odrv1.axis1.controller.input_vel = msg.data * 20
		self.get_logger.info("excavationAugerCallback: msg.data: " +str(msg.data))

	def excavationAngleCallback(self, msg):
		self.odrv1.axis0.controller.input_pos = msg.data
		self.get_logger.info("excavationAngleCallback: msg.data: " + str(msg.data))

	def calibrate(self):
		self.odrv0.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
		while self.odrv0.axis0.current_state != AXIS_STATE_IDLE:
			time.sleep(0.1)
		self.odrv0.axis1.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
		while self.odrv0.axis1.current_state != AXIS_STATE_IDLE:
			time.sleep(0.1)
		print("Calibrated")

	def init(self):
		super.__init__('excavation_node')
		self.excavationElevationSubscription = self.create_subscription(Float32, 'excavationElevation', self.excavationElevationCallback, 10)
		self.excavationAugerSubscription = self.create_subscription(Float32, 'excavationAuger', self.excavationAugerCallback, 10)
		self.excavationAngleSubscription = self.create_subscription(Float32, 'excavationAngle', self.excavationAngleCallback, 10)
		findODriveObjects()
		calibrate()
		print("ODrive Voltage: " + str(self.odrv0.allDrives[0]))
		setRequestedState()

def main(args=None):
	rclpy.init(args=args)
	print("Hello from exavation node")
	excavation_node = ExcavationNode('excavation_node')

	rclpy.spin(excavation_node)

	excavation_node.destroy_node()
	rclpy.shutdown()


if __name__ == '__main__':
    main()

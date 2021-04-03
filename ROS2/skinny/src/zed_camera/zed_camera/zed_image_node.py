import rclpy
from rclpy.node import Node

import numpy as np
import cv2
from sensor_msgs.msg import Image

TIME_INTERVAL = 0.5 # 1/2 second

class ZedImageNode(Node):
    """A ZED camera node that publishes an image
    every TIME_INTERVAL seconds to the detector node
    (in openrobotics_darknet_ros). Essentially,
    when active, it sends images to be analyzed
    through the object recognition detector.
    """


    def __init__(self):
        super().__init__('zed_image_node')

        # Set up image publisher
        self.publisher_ = self.create_publisher(Image, '/detector_node/images', 10) # Publish to '~/images' topic (same as detector_node)
        timer_period    = 3    # seconds
        self.timer      = self.create_timer(TIME_INTERVAL, self.timer_callback)

        # Set up ZED camera subscriber (RGB rectified)
        self.subscription = self.create_subscription(
            Image,
            'rgb/image_rect_color', # TODO is this correct? https://www.stereolabs.com/docs/ros2/
            self.listener_callback,
            10
        )
        self.subscription      # Prevent unused variable warning
        self.im_cache  = None  # Temporary cache for the image
        self.i          = 0    # Iterator to track image publication frame ID



    def timer_callback(self):
        """Called every TIME_INTERVAL seconds,
        publishes an image from the ZED camera to
        the DarkNet detector node.
        """

        # Check if the image cache is occupied
        if(type(self.im_cache) == type(None)):
            return

        # Convert image to rgb8
        im_data     = self.im_cache.data
        im_height   = self.im_cache.height
        im_width    = self.im_cache.width
        im_encoding = self.im_cache.encoding

        if(im_encoding != sensor_msgs.image_encodings.BGRA8)
            self.get_logger.info('Encoding {} is not allowed. Use "bgra8" instead.'.format(im_encoding))
            return

        # im_data = np.frombuffer(im_data, np.uint8)
        # im_data = im_data.reshape(im_height, im_width, 4)
        im_data = np.frombuffer(im_data, np.uint8).reshape(im_height, im_width, 4)
        im_rgb  = cv2.cvtColor(im_data, cv2.COLOR_BGRA2RGB)

        # Create an Image message and publish it
        msg = Image()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = str(self.i) # TODO optical frame of the camera?

        msg.height = im_height
        msg.width  = im_width

        # msg.encoding = 'rgb8' # Taken from include/sensor_msgs/image_encodings.h
        msg.encoding = sensor_msgs.image_encodings.RGB8 # Taken from include/sensor_msgs/image_encodings.h

        msg.is_bigendian = False        # Works with Darknet
        msg.step         = 3 * im_width # Full row length in bytes
        msg.data         = np.array(im_rgb).tobytes() # Flattened image data, size is (step * rows)

        self.publisher_.publish(msg)
        self.get_logger().info('Publishing image to Darknet...')
        self.get_logger().info('    Width : {} px'.format(im_width))
        self.get_logger().info('    Height: {} px'.format(im_height))
        self.get_logger().info('    Size  : {} bytes'.format(len(msg.data)))

        # Increase i to increase frame ID
        self.i += 1



    def listener_callback(self, msg):
        """Whenever ZED node pushes an image,
        stores the image in the cache and pushes it
        out the next time the timer hits zero.
        """
        self.get_logger().info('Recevied image from ZED...')
        self.get_logger().info('    Width : {} px'.format(msg.width))
        self.get_logger().info('    Height: {} px'.format(msg.height))
        self.get_logger().info('    Size  : {} bytes'.format(len(msg.data)))
        self.get_logger().info('    Time  : {}.{} sec'.format(msg.header.stamp.sec, msg.header.stamp.nanosec))

        self.im_cache = msg



def main(args=None):
    rclpy.init(args = args)
    zed_image_node = ZedImageNode()

    rclpy.spin(zed_image_node)

    # Destroy the node explicitly
    zed_image_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
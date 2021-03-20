import rclpy
from rclpy.node import Node

import numpy as np
from PIL import Image as PILImage
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
        timer_period    = 3  # seconds
        self.timer      = self.create_timer(TIME_INTERVAL, self.timer_callback)

    def timer_callback(self):
        """Called every TIME_INTERVAL seconds,
        publishes an image from the ZED camera to
        the detector node.
        """

        # TODO get the ZED image here! (as im)


        # Create an Image message and publish it
        msg = Image()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = str(self.i) # TODO optical frame of the camera?

        msg.height = im.height
        msg.width  = im.width

        msg.encoding = 'rgb8' # Taken from include/sensor_msgs/image_encodings.h

        msg.is_bigendian = False # IDK if it is, let's try this LOL
        msg.step         = 3 * im.width # Full row length in bytes
        msg.data         = np.array(im).tobytes() # Flattened image data, size is (step * rows)

        self.publisher_.publish(msg)
        self.get_logger().info('Publishing image from ZED...')
        self.get_logger().info('    Width : {} px'.format(im.width))
        self.get_logger().info('    Height: {} px'.format(im.height))





def main(args=None):
    rclpy.init(args = args)
    zed_image_node = ZedImageNode()

    rclpy.spin(zed_image_node)

    # Destroy the node explicitly
    zed_image_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
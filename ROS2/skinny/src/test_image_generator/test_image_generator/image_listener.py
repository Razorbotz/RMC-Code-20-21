import rclpy
from rclpy.node import Node

import numpy as np
from sensor_msgs.msg import Image
from vision_msgs.msg import Detection2DArray

# Dummy node that only listens
# to image predictions that DarkNet has parsed.

class ImageListener(Node):

    def __init__(self):
        super().__init__('image_listener')

        # Set up detection listener
        self.subscription = self.create_subscription(
            Detection2DArray,
            '/detector_node/detections',
            self.listener_callback,
            10
        )
        self.subscription # Prevent unused variable warning



    def listener_callback(self, msg):
        '''Called whenever the detector_node
        finishes analyzing the image through YOLO.
        '''
        self.get_logger().info('Received detection list')

        for det in msg.detections:
            for res in det.results:
                class_id   = res.id
                confidence = res.score
                self.get_logger().info('\n    Class:')
                self.get_logger().info('        ID        : {}'.format(class_id))
                self.get_logger().info('        Confidence: {}'.format(confidence))

            bbox_center_x = det.bbox.center.x
            bbox_center_y = det.bbox.center.y
            bbox_width  = det.bbox.size_x
            bbox_height = det.bbox.size_y

            self.get_logger().info('    Bounding box:')
            self.get_logger().info('        Center    : {}, {}'.format(bbox_center_x, bbox_center_y))
            self.get_logger().info('        Dimensions: {}, {}'.format(bbox_width, bbox_height))


def main(args=None):
    rclpy.init(args = args)

    image_listener = ImageListener()

    rclpy.spin(image_listener)

    # Destroy the node explicitly
    image_listener.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

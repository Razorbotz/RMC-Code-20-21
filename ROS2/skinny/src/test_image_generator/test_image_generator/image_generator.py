import rclpy
from rclpy.node import Node

import os, glob
import numpy as np
from PIL import Image as PILImage
from sensor_msgs.msg import Image
from vision_msgs.msg import Detection2DArray

# Dummy node that publishes a series of images in the /root/sample_img folder to
# test the detector node + network.

class ImageGenerator(Node):

    def __init__(self):
        super().__init__('image_generator')

        # Set up runtime parameters
        # im_dir      : Where the images are expected to be sourced from
        # timer_period: The time (seconds) between publishing images
        self.declare_parameters(
            namespace='',
            parameters=[
                ('im_dir', "/home/team/Vision/images/"),
                ('timer_pd', 3)
            ]
        )

        # Generate a list of .jpg images stored in im_path
        im_dir        = str(self.get_parameter('im_dir').value)
        self.im_paths = glob.glob(os.path.join(im_dir, '*.jpg'))
        self.get_logger().info('Found {} images in {}'.format(len(self.im_paths), im_dir))

        # Set up image generation publisher
        self.publisher_ = self.create_publisher(Image, '/detector_node/images', 10) # Publish to '~/images' topic (same as detector_node)
        timer_pd        = float(self.get_parameter('timer_pd').value)
        self.timer      = self.create_timer(
            timer_pd, 
            self.timer_callback
        )
        self.i = 0 # Iterator to loop through each of the images in the im_paths list.

        # Set up detection listener
        self.subscription = self.create_subscription(
            Detection2DArray,
            '/detector_node/detections',
            self.listener_callback,
            10
        )
        self.subscription # Prevent unused variable warning


    def timer_callback(self):
        '''Called every (timer_pd) seconds,
        publishes an image from /root/images/ that the
        detector_node will take in and process.
        '''
        # Check for out of bounds indexes in im_paths list
        # If we have reached the end of the set of images, stop publishing new images.
        if self.i < 0 or self.i >= len(self.im_paths):
            self.get_logger().info('All images have been processed.')
            return

        # Check for nonexistent image/path
        if os.path.exists(self.im_paths[self.i]):
            im  = PILImage.open(self.im_paths[self.i])
        else:
            self.i = self.i + 1 # If this image does not exist, increment i and try again later with the next image.
            self.get_logger().info('Image {} not found. Skipping...'.format(self.im_paths[i]))
            return

        im      = im.convert('RGB')
        im_data = np.array(im)


        msg = Image()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = str(self.i)

        msg.height = im.height
        msg.width  = im.width

        msg.encoding = 'rgb8' # Taken from include/sensor_msgs/image_encodings.h

        msg.is_bigendian = False
        msg.step         = 3 * im.width           # Full row length in bytes
        msg.data         = np.array(im).tobytes() # Flattened image data, size is (step * rows)

        self.publisher_.publish(msg)
        self.get_logger().info('Publishing image {}...'.format(self.im_paths[self.i]))
        self.get_logger().info('    Width : {} px'.format(im.width))
        self.get_logger().info('    Height: {} px'.format(im.height))

        self.i = self.i + 1 # Increment i (until we run out of images).


    def listener_callback(self, msg):
        '''Called whenever the detector_node
        finishes analyzing the image through YOLO.
        '''
        self.get_logger().info('Received detection list...')

        for det in msg.detections:
            for res in det.results:
                class_id   = res.id
                confidence = res.score
                self.get_logger().info('    Class:')
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

    image_generator = ImageGenerator()

    rclpy.spin(image_generator)

    # Destroy the node explicitly
    image_generator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

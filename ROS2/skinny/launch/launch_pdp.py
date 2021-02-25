from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='power_distribution_panel',
            namespace='',
            name='power_distribution_panel',
            executable='power_distribution_panel_node'
        )
    ]
)

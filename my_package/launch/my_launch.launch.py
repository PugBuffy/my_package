import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument

from launch.substitutions import LaunchConfiguration

def generate_launch_description():

    my_package_path = get_package_share_directory("my_package")
    config_file = os.path.join(my_package_path, "config", "my_params.yaml")

    msg_publisher = Node(   
        package="my_package", 
        executable="msg_pub",
        parameters=[config_file]
    )

    my_node = Node(
        package="my_package",
        executable="main_node"
    )

    ld = LaunchDescription()

    ld.add_action(msg_publisher)
    ld.add_action(my_node)

    return LaunchDescription([msg_publisher,
                              my_node]) 
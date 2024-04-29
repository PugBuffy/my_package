#include "my_package/my_node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<my_node_namespace::MyNode>());
  rclcpp::shutdown();
  return 0;
}
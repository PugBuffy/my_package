#include "my_package/my_node.hpp"

using namespace std::placeholders;

namespace my_node_namespace
{
    MyNode::MyNode() : Node("my_node")
    {   
        publisher = this->create_publisher<std_msgs::msg::String>("/topic", 10);
        subscriber = this->create_subscription<std_msgs::msg::String>("/message", 10, std::bind(&MyNode::callback, this, _1));
    }   

    void MyNode::callback(const std_msgs::msg::String& object)
    {
        auto msg = std_msgs::msg::String();
        msg.data = "Hello " + object.data + "!";

        RCLCPP_INFO(this->get_logger(), msg.data.c_str());
        publisher->publish(msg);
    }
}

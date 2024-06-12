#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace my_node_namespace
{
    class MyNode : public rclcpp::Node
    {
        public:
            MyNode();

        private:
            void callback(const std_msgs::msg::String &msg);
            rclcpp::TimerBase::SharedPtr timer;
            rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
            rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber;
            
    };
}

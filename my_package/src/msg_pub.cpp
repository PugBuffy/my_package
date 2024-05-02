#include <memory>
#include <chrono>
#include <string>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MsgPublisher : public rclcpp::Node
{
    public:
        MsgPublisher() : Node("msg_pub")
        {  
           this->declare_parameter("msg", "world");

           publisher = this->create_publisher<std_msgs::msg::String>("/message", 10);
           timer = this->create_wall_timer(500ms, std::bind(&MsgPublisher::topic_callback, this));

           RCLCPP_INFO(this->get_logger(), "Start sending...");
        }   
    
    private:
        void topic_callback()
        {   
            auto msg = std_msgs::msg::String();
            msg.data = this->get_parameter("msg").get_parameter_value().get<std::string>();
            publisher->publish(msg);
        }
        
        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MsgPublisher>());
    rclcpp::shutdown();
    return 0;
}
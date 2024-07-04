cmake_minimum_required(VERSION 3.8)
project(new_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include/${PROJECT_NAME})

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)

add_subdirectory(my_lib)


add_executable(main_node src/main_pub.cpp src/my_node.cpp)
ament_target_dependencies(main_node rclcpp std_msgs)
target_link_libraries(main_node my_lib) 

add_executable(msg_pub src/msg_pub.cpp)
ament_target_dependencies(msg_pub rclcpp) 


install(TARGETS
  msg_pub
  main_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

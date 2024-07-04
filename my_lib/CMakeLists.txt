cmake_minimum_required(VERSION 3.8)
project(my_lib)

file(GLOB FUNCS include/funcs.hpp src/funcs.cpp)

add_library(${PROJECT_NAME} STATIC ${FUNCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

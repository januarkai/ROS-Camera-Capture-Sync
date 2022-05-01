cmake_minimum_required(VERSION 3.0.2)
project(sensor_capture)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
  cv_bridge
  image_transport
  message_filters
  rosbag
)
find_package(Boost REQUIRED)
find_package(OpenCV REQUIRED)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ${PROJECT_NAME}
 CATKIN_DEPENDS roscpp sensor_msgs std_msgs cv_bridge image_transport message_filters rosbag
 DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

include_directories(/home/januar/Desktop/SensorCapture/src/sensor_capture/include
                    /home/januar/Desktop/SensorCapture/src/sensor_capture/include/sensor_capture
                    /home/januar/Desktop/SensorCapture/src/sensor_capture/include/sensor_capture/nodes) 
include_directories(&{Boost_INCLUDE_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})

link_directories(${OpenCV_LIBRARY_DIRS})

set(sync src/sub_sync.cpp)

add_executable(sub_node src/nodes/cam_sub_sync_node.cpp ${sync})
target_link_libraries(sub_node ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(sub_node ${catkin_EXPORTED_TARGETS})


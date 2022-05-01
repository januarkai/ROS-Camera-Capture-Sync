#ifndef CAMERA_NODE_HPP
#define CAMERA_NODE_HPP

#include "gige_camera.hpp"
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

class ImageData {
public:
    void imageCallback(const sensor_msgs::ImageConstPtr& msg);
    cv::Mat cv_mat_image;
    sensor_msgs::ImagePtr image_msg_ptr;
};

#endif
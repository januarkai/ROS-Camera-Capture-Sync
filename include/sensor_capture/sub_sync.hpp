#ifndef SUB_SYNC_HPP
#define SUB_SYNC_HPP

#include <ros/ros.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <rosbag/bag.h>
#include <boost/bind.hpp>
// #include <opencv2/opencv.hpp>

class ImageData {
public:
    ImageData();

    int width;
    int height;
    int channels;
private:
    unsigned char* _image_data_ptr;
};

typedef message_filters::sync_policies::ApproximateTime<
                                                        sensor_msgs::Image, 
                                                        sensor_msgs::Image, 
                                                        sensor_msgs::Image, 
                                                        sensor_msgs::Image, 
                                                        sensor_msgs::Image, 
                                                        sensor_msgs::Image, 
                                                        sensor_msgs::Image, 
                                                        sensor_msgs::Image 
                                                        // sensor_msgs::Image
                                                                           > my_sync_policy;
class Collect {
public:
    Collect();
    virtual ~Collect();
    ros::NodeHandle nh;
    void callback(const sensor_msgs::ImageConstPtr &image1,
                  const sensor_msgs::ImageConstPtr &image2,
                  const sensor_msgs::ImageConstPtr &image3,
                  const sensor_msgs::ImageConstPtr &image4,
                  const sensor_msgs::ImageConstPtr &image5,
                  const sensor_msgs::ImageConstPtr &image6,
                  const sensor_msgs::ImageConstPtr &image7,
                  const sensor_msgs::ImageConstPtr &image8);
                //   const sensor_msgs::ImageConstPtr &image9);
private:
    message_filters::Subscriber<sensor_msgs::Image> *_image1;
    message_filters::Subscriber<sensor_msgs::Image> *_image2;
    message_filters::Subscriber<sensor_msgs::Image> *_image3;
    message_filters::Subscriber<sensor_msgs::Image> *_image4;
    message_filters::Subscriber<sensor_msgs::Image> *_image5;
    message_filters::Subscriber<sensor_msgs::Image> *_image6;
    message_filters::Subscriber<sensor_msgs::Image> *_image7;
    message_filters::Subscriber<sensor_msgs::Image> *_image8;
    // message_filters::Subscriber<sensor_msgs::Image> *_image9;

    message_filters::Synchronizer<my_sync_policy> *_sync_message;

    int _seq;
    rosbag::Bag _bag;
};


#endif 
#include "sub_sync.hpp"

Collect::Collect() {
    _image1 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image1", 30);
    _image2 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image2", 30);
    _image3 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image3", 30);
    _image4 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image4", 30);
    _image5 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image5", 30);
    _image6 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image6", 30);
    _image7 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image7", 30);
    _image8 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "/camera/image8", 30);
    // _image9 = new message_filters::Subscriber<sensor_msgs::Image>(nh, "camera/image9", 30);

    _sync_message = new message_filters::Synchronizer<my_sync_policy>(my_sync_policy(1000), *_image1,
                                                                                          *_image2,
                                                                                          *_image3,
                                                                                          *_image4,
                                                                                          *_image5,
                                                                                          *_image6,
                                                                                          *_image7,
                                                                                          *_image8);
                                                                                        //   *_image9);
    _seq = 0;
    _sync_message->registerCallback(boost::bind(&Collect::callback, this, _1, _2, _3, _4, _5, _6, _7, _8));
    _bag.open("/home/januar/Desktop/bagfiles/test3.bag", rosbag::bagmode::Write);
}

Collect::~Collect() {
    _bag.close();
}

void Collect::callback(const sensor_msgs::ImageConstPtr &image1,
                       const sensor_msgs::ImageConstPtr &image2,
                       const sensor_msgs::ImageConstPtr &image3,
                       const sensor_msgs::ImageConstPtr &image4,
                       const sensor_msgs::ImageConstPtr &image5,
                       const sensor_msgs::ImageConstPtr &image6,
                       const sensor_msgs::ImageConstPtr &image7,
                       const sensor_msgs::ImageConstPtr &image8){
                    //    const sensor_msgs::ImageConstPtr &image9) {
    std:: cout << "Seq: " << _seq << ": ";
    std::cout << "Image1: " << image1->header.stamp << " ";
    std::cout << "Image2: " << image2->header.stamp << " ";
    std::cout << "Image3: " << image3->header.stamp << " ";
    std::cout << "Image4: " << image4->header.stamp << " ";
    std::cout << "Image5: " << image5->header.stamp << " ";
    std::cout << "Image6: " << image6->header.stamp << " ";
    std::cout << "Image7: " << image7->header.stamp << " ";
    std::cout << "Image8: " << image8->header.stamp << " ";
    // std::cout << "Image9: " << image9->header.stamp << " ";
    std::cout << std::endl;

    ros::Time times = ros::Time::now();

    _bag.write("/camera/image1", times, image1);
    _bag.write("/camera/image2", times, image2);
    _bag.write("/camera/image3", times, image3);
    _bag.write("/camera/image4", times, image4);
    _bag.write("/camera/image5", times, image5);
    _bag.write("/camera/image6", times, image6);
    _bag.write("/camera/image7", times, image7);
    _bag.write("/camera/image8", times, image8);
    // _bag.write("camera/image9", times, image9);

    _seq+=1;
}
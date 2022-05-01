#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

void epoch(uint64_t& timestamp) {
    while (1)
    {
        timestamp = boost::chrono::duration_cast<boost::chrono::microseconds>(boost::chrono::system_clock::now().time_since_epoch()).count();
    }
    
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "Timestamp_Provider");
    ros::NodeHandle n;

    ros::Publisher publisher = n.advertise<std_msgs::String>("Timestamp", 1000);

    ros::Rate loop_rate(30);

    uint64_t timestamp;

    boost::thread thread1(epoch, std::ref(timestamp));
    if(thread1.joinable()) {
        thread1.detach();
    }

    int count = 0;
    while(ros::ok()) {
        std_msgs::String messages;
        messages.data = std::to_string(timestamp);
        ROS_INFO("%s", messages.data.c_str());
        publisher.publish(messages);
        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}

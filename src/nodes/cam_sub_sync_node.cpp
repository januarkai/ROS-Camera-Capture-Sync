#include "sub_sync.hpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "Sub_node1");
    Collect mycollect;
    ros::spin();
    return 0;
}
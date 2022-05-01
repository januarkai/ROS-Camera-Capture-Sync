#ifndef CAMERA_ACCESS_CONTROL
#define CAMERA_ACCESS_CONTROL

#include "camera_properties.hpp"
#include <opencv2/opencv.hpp>

namespace FIXIO{
    class CameraInterface {
    public:
        virtual void initCamera() = 0;
        virtual void setCameraProperties(CameraProperties cam_prop) = 0;
        virtual void startStream() = 0;
        virtual cv::Mat getFrame(CameraPosition cam_pos) = 0;
        virtual void deinitCamera() = 0;
        CameraProperties getCameraProperties() {
            return cam_prop_;
        }
    protected:
        CameraProperties cam_prop_;
    };
}

#endif
#ifndef CAMERA_PROPERTIES_HPP
#define CAMERA_PROPERTIES_HPP

#include<iostream>

namespace FIXIO {
    enum CameraPosition {
        FRONT_LEFT = 0,
        FRONT_RIGHT = 1,
        FRONT_LEFT_CORNER = 2,
        FRONT_RIGHT_CORNER = 3,
        LEFT_SIDE = 4,
        RIGHT_SIDE = 5,
        REAR_LEFT_CORNER = 6,
        REAR_RIGHT_CORNER = 7,
        REAR = 8
    };

    enum Resolution {
        FULL_RESOLUTION = 0,
        HALF_RESOLUTION = 1
    };

    struct CameraProperties {
        int32_t width_54;
        int32_t height_54;

        int32_t width_23;
        int32_t height_23;

        float fps_54;
        float fps_23;

        float gain_54;
        float gain_23;

        int32_t packet_delay;
        Resolution resolution_54;
        Resolution resolution_23;

        CameraProperties() : width_54(2880), height_54(1860), fps_54(24.0), gain_54(0.0), width_23(1920), height_23(1200), fps_23(47.0), gain_23(0.0), packet_delay(80000), resolution_54(Resolution::HALF_RESOLUTION), resolution_23(Resolution::FULL_RESOLUTION){}
    };
}

#endif
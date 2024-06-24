#pragma once

extern "C" {
    #include <libavcodec/avcodec.h>
}

class Frame : AVFrame {
public:
    Frame();
    ~Frame();
};
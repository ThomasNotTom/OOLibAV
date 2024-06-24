#include <iostream>

#include "../include/Frame.hpp"

Frame::Frame() {
    AVFrame* tempFrame = av_frame_alloc();
    if (!tempFrame) {
        std::cerr << "ERROR: AVFrame could not be allocated" << std::endl;
        return;
    }
    std::memcpy(static_cast<AVFrame*>(tempFrame), tempFrame, sizeof(AVFrame));
    av_frame_free(&tempFrame);
}

Frame::~Frame() {
    av_frame_free(reinterpret_cast<AVFrame**>(this));
}
#include <iostream>

#include "../include/CodecContext.hpp"


CodecContext::CodecContext(const AVCodec* codec) {
    this->codecContext = avcodec_alloc_context3(codec);
    if (!this->codecContext) {
        std::cerr << "ERROR: Could not allocate context" << std::endl;
        return;
    }
}

CodecContext::~CodecContext() {
    avcodec_free_context(&this->codecContext);
}

AVCodecContext* CodecContext::operator->() {
    return this->codecContext;
}
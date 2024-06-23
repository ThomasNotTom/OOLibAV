extern "C" {
    #include <libavcodec/avcodec.h>
}

#include "../include/CodecContext.hpp"

CodecContext::CodecContext(const AVCodec* codec) {
    this->codecContext = avcodec_alloc_context3(codec);
}

AVCodecContext* CodecContext::operator->() {
    return codecContext;
}
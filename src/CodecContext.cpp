#include <iostream>

#include "../include/CodecContext.hpp"

CodecContext::CodecContext(const AVCodec* codec) {
    AVCodecContext* tempCtx = avcodec_alloc_context3(codec);
    if (!tempCtx) {
        std::cerr << "ERROR: AVCodecContext could not be allocated" << std::endl;
        return;
    }
    std::memcpy(static_cast<AVCodecContext*>(tempCtx), tempCtx, sizeof(AVCodecContext));
    avcodec_free_context(&tempCtx);
}

int CodecContext::open(AVDictionary **options) {
    return avcodec_open2(this, this->codec, options);
}

int CodecContext::sendFrame(Frame* frame) {
    return avcodec_send_frame(this, (AVFrame*) frame);
}

int CodecContext::recieveFrame(Frame* frame) {
    return avcodec_receive_frame(this, (AVFrame*) frame);
}

int CodecContext::sendPacket(Packet* packet) {
    return avcodec_send_packet(this, (AVPacket*) packet);
}

int CodecContext::recievePacket(Packet* packet) {
    return avcodec_receive_packet(this, (AVPacket*) packet);
}

CodecContext::~CodecContext() {
    avcodec_free_context(reinterpret_cast<AVCodecContext**>(this));
}
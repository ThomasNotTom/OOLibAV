#pragma once

extern "C" {
    #include <libavcodec/avcodec.h>
}

#include "../include/Frame.hpp"
#include "../include/Packet.hpp"

class CodecContext : public AVCodecContext {
public:
    CodecContext(const AVCodec* codec);
    int CodecContext::setParameters(AVCodecParameters* parameters);
    int open(AVDictionary **options);

    int CodecContext::sendFrame(Frame* frame);
    int CodecContext::recieveFrame(Frame* frame);

    int CodecContext::sendPacket(Packet* packet);
    int CodecContext::recievePacket(Packet* packet);
    
    ~CodecContext();
};
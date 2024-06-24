#pragma once

extern "C" {
    #include <libavcodec/avcodec.h>
}

class Packet : AVPacket {
public:
    Packet();
    ~Packet();
};
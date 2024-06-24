#pragma once

extern "C" {
    #include <libavcodec/avcodec.h>
}

class CodecContext : public AVCodecContext {
public:
    CodecContext(const AVCodec* codec);
    ~CodecContext();

    AVCodecContext* operator->();

private:
    AVCodecContext* codecContext;
};
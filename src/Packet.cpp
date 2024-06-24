#include <iostream>

#include "../include/Packet.hpp"

Packet::Packet() {
    AVPacket* tempPacket = av_packet_alloc();
    if (!tempPacket) {
        std::cerr << "ERROR: AVPacket could not be allocated" << std::endl;
        return;
    }
    std::memcpy(static_cast<AVPacket*>(tempPacket), tempPacket, sizeof(AVPacket));
    av_packet_free(&tempPacket);
}

Packet::~Packet() {
    av_packet_free(reinterpret_cast<AVPacket**>(this));
}
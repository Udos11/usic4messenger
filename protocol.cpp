#include "protocol.h"
#include <cstring>

// ������������ ���������
std::string serializeHeader(const PacketHeader& header) {
    std::string buffer(sizeof(PacketHeader), 0);
    memcpy(&buffer[0], &header.type, sizeof(header.type));
    memcpy(&buffer[sizeof(header.type)], &header.length, sizeof(header.length));
    return buffer;
}

// �������������� ���������
PacketHeader deserializeHeader(const std::string& data) {
    PacketHeader header;
    memcpy(&header.type, &data[0], sizeof(header.type));
    memcpy(&header.length, &data[sizeof(header.type)], sizeof(header.length));
    return header;
}

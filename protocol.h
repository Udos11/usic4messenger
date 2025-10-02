#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <vector>

// ���� ���������
enum MessageType {
    HELLO = 1,
    PEER_LIST = 2,
    MESSAGE = 3
};

// ��������� ��������� ������
struct PacketHeader {
    uint8_t type;       // ��� ���������
    uint32_t length;    // ����� ������
};

// ������� ��� ������������ ���������
std::string serializeHeader(const PacketHeader& header);

// ������� ��� �������������� ���������
PacketHeader deserializeHeader(const std::string& data);

#endif

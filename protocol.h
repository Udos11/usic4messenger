#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <vector>

// Типы сообщений
enum MessageType {
    HELLO = 1,
    PEER_LIST = 2,
    MESSAGE = 3
};

// Структура заголовка пакета
struct PacketHeader {
    uint8_t type;       // Тип сообщения
    uint32_t length;    // Длина данных
};

// Функция для сериализации заголовка
std::string serializeHeader(const PacketHeader& header);

// Функция для десериализации заголовка
PacketHeader deserializeHeader(const std::string& data);

#endif

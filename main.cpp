#include <iostream>
#include <winsock2.h>
#include "protocol.h"

#pragma comment(lib, "ws2_32.lib")

void sendMessage(SOCKET socket, const std::string& message) {
    PacketHeader header;
    header.type = MESSAGE;
    header.length = message.size();

    std::string serializedHeader = serializeHeader(header);
    send(socket, serializedHeader.c_str(), serializedHeader.size(), 0);
    send(socket, message.c_str(), message.size(), 0);
}

std::string receiveMessage(SOCKET socket) {
    char buffer[sizeof(PacketHeader)];
    recv(socket, buffer, sizeof(PacketHeader), 0);

    PacketHeader header = deserializeHeader(buffer);
    std::string data(header.length, 0);
    recv(socket, &data[0], header.length, 0);
    return data;
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    // ???????? ?????????
    sendMessage(serverSocket, "Hello, peer!");

    // ????????? ?????????
    std::string received = receiveMessage(serverSocket);
    std::cout << "Received: " << received << std::endl;

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

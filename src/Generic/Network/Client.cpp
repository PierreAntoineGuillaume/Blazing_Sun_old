#include "Client.h"

Client::Client(){}

sf::TcpSocket socket;
sf::Packet packet;

void Client::connect(sf::IpAddress ipAddress, int numPort){
    sf::Socket::Status status = socket.connect(ipAddress, numPort);
    if(status != sf::Socket::Done){
        cout << "Bad ip or port";
    }
}

void Client::sendData(char data[]){
    if(!socket.send(data, data.size())){
        std::cout << "Sending error" << std::endl;
    }
}

void Client::receiveData() {
    if (socket.receive(packet) == sf::Socket::Done) {
        packet.analyse();
    }
}

//TODO : analyse() depends of the user's will


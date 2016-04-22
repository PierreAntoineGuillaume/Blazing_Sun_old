#include "Client.h"

Client::Client(){}

sf::TcpSocket socket;

void Client::connect(sf::IpAddress ipAddress, int numPort){
    sf::Socket::Status status = socket.connect(ipAddress, numPort);
    if(status != sf::Socket::Done){
        cout << "Bad ip or port";
    }
}

void Client::sendData(char data[]){
    if(!socket.send(data, data.size())){
        std::cout << "Erreur d'envoi" << std::endl;
    }
}




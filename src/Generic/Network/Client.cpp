
#include "Client.h"

#include <iostream>

Client::Client(){}

sf::TcpSocket socket;

namespace nsNetwork
{
    class packet : public sf::Packet
    {
    public:
        void process () {

        }
    };
}

nsNetwork::packet packet;


void Client::connect(const sf::IpAddress & ipAddress, unsigned short numPort){
    sf::Socket::Status status = socket.connect(ipAddress, numPort);
    if(status != sf::Socket::Done){
        std::cout << "Bad ip or port";
    }
}

void Client::sendData(const std::string & data){
    if(!socket.send(data.c_str(), data.size())){
        std::cout << "Sending error" << std::endl;
    }
}

void Client::receiveData() {
    if (socket.receive(packet) == sf::Socket::Done) {

        packet.process();
    }
}

//TODO : analyse() depends of the user's will


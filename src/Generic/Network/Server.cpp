#include "Server.h"

#include <list>
#include <iostream>


Server::Server(){}





void Server::serverStart(int numPort){

    if (listener.listen(numPort) != sf::Socket::Done){
        std::cout << "Bad port";
    }
    else
    {
        //selector.Add(listener);
    }


}

void Server::acceptConnection(){
    /** /
    while (true){
        unsigned int nbSocket = selector.Wait();

        for (unsigned i(0); i < nbSocket; ++i){
            socket = selector.GetSocketReady(i);

            if(socket == listener){
                sf::TcpSocket client;

                listener.accept(client);
                std::cout << "Client connected ("
                << client.getRemoteAddress () << ")" << std::endl;
                clients.push_back(client);
                selector.add(client);
            }
            else{

            }
        }
    }
    /**/
}

void Server::transmitData(){

    /** /
    sf::Packet packet;

    if (socket.receive(packet) == sf::Socket::Done){
        for (sf::TcpSocket client : clients){
            client.send(packet, packet.size.length);
        }
    }
    else
        selector.remove(socket);
    /**/
}


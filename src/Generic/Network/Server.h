#pragma once

#include <SFML/Network.hpp>
#include <list>


class Server {
    sf::TcpListener listener;
    sf::TcpSocket socket;
    std::list<sf::TcpSocket> clients;
//    sf::SelectorTCP selector;

public:
    Server();


    /*
     * start a server on the specifical port
     */
    void serverStart(int numPort);

    /*
     * accept any connection from a client
     */
    void acceptConnection();


    /*
     * allow the server to receive some datas and send them back to all the clients
     */
    void transmitData();


};
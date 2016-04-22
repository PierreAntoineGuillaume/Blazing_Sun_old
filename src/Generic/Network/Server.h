#pragma once

#include <SFML/Network.hpp>


class Server{

public:
    Server();


    /*
     * start a server on the specifical port
     */
    void Server::serverStart(int numPort);

    /*
     * accept any connection from a client
     */
    void Server::acceptConnection();


    /*
     * allow the server to receive some datas and send them back to all the clients
     */
    void Server::transmitData();


};
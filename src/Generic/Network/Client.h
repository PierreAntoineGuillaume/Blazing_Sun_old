#pragma once

#include <SFML/Network.hpp>


class Client{

public:
    Client();

    /*
     * connect the client to the server with the specific ipAddress:numPort
     */
    void connect(sf::IpAddress ipAddress, int numPort);


    /*
     * allow the client to send data to the server
     */
    void sendData(char data[]);

    /*
     * gets the server's data and call the treatment function
     */
    void receiveData();

};


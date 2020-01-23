//
// Created by yuval on 1/23/20.
//

#include <thread>
#include "MySerialServer.h"
#include "TcpServer.h"


server_side::MySerialServer::MySerialServer() {
    this->keepRunning = new bool();
    *(this->keepRunning) = true;

}

void server_side::MySerialServer::open(int port, server_side::IClientHandler *clientHandler) {

    serverThread = std::thread([](int port,server_side::IClientHandler *clientHandler, bool* keepRunning){

        int mainSocketId = TcpServer::listenToPort(port);

        bool isFirstClient = true;

        while (*keepRunning) {

            int clientSocketId = TcpServer::acceptConnection(mainSocketId);
            //if the timeout time passed, stop the server
            if(clientSocketId < 0) {

                if(!isFirstClient){
                    break;
                } else{
                    continue;
                }

            } else if(isFirstClient){
                isFirstClient= false;
            }
            clientHandler->handleClient(clientSocketId);
            TcpServer::closeSocket(clientSocketId);

        }

        TcpServer::closeSocket(mainSocketId);

    }, port, clientHandler, keepRunning);

    joinThreads();

}

void server_side::MySerialServer::joinThreads(){

    //wait for the thread to end
    serverThread.join();
}

void server_side::MySerialServer::stop() {

    *(this->keepRunning) = false;

}
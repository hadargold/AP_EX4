//
// Created by yuval on 1/23/20.
//

#include <thread>
#include "MyParallelServer.h"
#include "TcpServer.h"


server_side::MyParallelServer::MyParallelServer() {

    this->continueToRun = new bool();
    *(this->continueToRun) = true;

    this->clientsThreads = new std::vector<std::thread>;

}


void server_side::MyParallelServer::open(int port, server_side::IClientHandler *clientHandler) {

    serverThread = thread([](int port, std::vector<std::thread>* clientsThreads,
                                  server_side::IClientHandler *clientHandler, bool* continueToRun){
        int socketIdForListening = TcpServer::listenToPort(port);
        bool firstClient = true;
        while (*continueToRun) {

            int clientSocketId = TcpServer::acceptConnection(socketIdForListening);
            
            if(clientSocketId < 0) {
                if(!firstClient){
                    break;
                } else{
                    continue;
                }

            } else if(firstClient){
                firstClient= false;
            }

            //add each client thread to the threads list
            clientsThreads->push_back(std::thread([clientHandler, clientSocketId](){

                clientHandler->handleClient(clientSocketId);

                TcpServer::closeSocket(clientSocketId);

            }));

        }
        // close the main socket
        TcpServer::closeSocket(socketIdForListening);

    }, port, this->clientsThreads, clientHandler, continueToRun);

    joinThreads();


}

void server_side::MyParallelServer::joinThreads(){
    // join all the threads
    serverThread.join();
    for (int i = 0; i < clientsThreads->size(); ++i) {
        (*clientsThreads)[i].join();
    }

}

void server_side::MyParallelServer::stop() {
    *(this->continueToRun) = false;
    joinThreads();

}

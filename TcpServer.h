//
// Created by yuval on 1/21/20.
//
#ifndef SERVERAPPLICATION_TCPSERVER_H
#define SERVERAPPLICATION_TCPSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

namespace server_side {

    class TcpServer {

    public:

        //return new main socketId
        static int listenToPort(int serverPort);

        //return new socketId
        static int acceptConnection(int mainSocketId);

        static std::string readLine(int socketId);

        static void writeToClient(int socketId, std::string message){
            ssize_t n;

            n = write(socketId, message.c_str(), message.length());

            if (n < 0) {
                perror("ERROR");
                exit(1);
            }
        };

        static void closeSocket(int socketId){
            close(socketId);
        };


    };

}

#endif //SERVERAPPLICATION_TCPSERVER_H

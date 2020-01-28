//
// Created by yuval on 1/20/20.
//
#ifndef SERVERAPPLICATION_CLIENTHANDLER_H
#define SERVERAPPLICATION_CLIENTHANDLER_H

#include <iostream>

namespace server_side{

    class IClientHandler {

    public:

        virtual void handleClient(int socketID) = 0;

        virtual ~IClientHandler() = default;
    };
    
}

#endif //SERVERAPPLICATION_CLIENTHANDLER_H

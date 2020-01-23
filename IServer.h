#ifndef SERVERAPPLICATION_ISERVER_H
#define SERVERAPPLICATION_ISERVER_H

#include "IClientHandler.h"

namespace server_side{

    class IServer{

    public:

        virtual void open(int port, IClientHandler *clientHandler) = 0;

        virtual void stop() = 0;

        virtual ~IServer() = default;
        
    };
    
}

#endif //SERVERAPPLICATION_ISERVER_H

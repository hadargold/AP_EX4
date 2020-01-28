//
// Created by yuval on 1/19/20.
//

#ifndef SERVERAPPLICATION_MYTESTCLIENTHANDLER_H
#define SERVERAPPLICATION_MYTESTCLIENTHANDLER_H

#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"
#include "TcpServer.h"
using namespace std;



namespace server_side {
    class MyTestClientHandler : public IClientHandler {
    private:
        ISolver<string, string> *solver;
        ICacheManager *cacheManager;
    public:
        virtual void handleClient(int socket);
        MyTestClientHandler(ISolver<string, string> *s, ICacheManager *c){
            this->solver = s;
            this->cacheManager = c;
        }
        ~MyTestClientHandler(){
            delete (solver);
            delete (cacheManager);
        }
    };
}

#endif //SERVERAPPLICATION_MYTESTCLIENTHANDLER_H

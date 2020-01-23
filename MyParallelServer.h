//
// Created by yuval on 1/23/20.
//

#ifndef SERVERAPPLICATION_MYPARALLELSERVER_H
#define SERVERAPPLICATION_MYPARALLELSERVER_H


#include <thread>
#include "IServer.h"
#include "vector"
using namespace std;

namespace server_side {

    class MyParallelServer : public IServer  {

        bool* continueToRun;
        thread serverThread;
        vector<thread>* clientsThreads;

        void joinThreads();

    public:

        MyParallelServer();

        void open(int port, IClientHandler *clientHandler) override;

        void stop() override;

        ~MyParallelServer() override{
            delete this->continueToRun;
            delete(clientsThreads);
        }

    };


}

#endif //SERVERAPPLICATION_MYPARALLELSERVER_H

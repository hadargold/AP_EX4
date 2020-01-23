//
// Created by yuval on 1/23/20.
//

#ifndef SERVERAPPLICATION_MYSERIALSERVER_H
#define SERVERAPPLICATION_MYSERIALSERVER_H

#include <thread>
#include "IServer.h"

namespace server_side{

    /**
     * defines a serial one client simultainly server
     */
    class MySerialServer : public IServer  {
        int i =0;
        bool* keepRunning;
        std::thread serverThread;

        void joinThreads();

    public:

        MySerialServer();

        void open(int port, IClientHandler *clientHandler) override;

        void stop() override;

        ~MySerialServer() override{
            delete this->keepRunning;
        }

    };



}



#endif //SERVERAPPLICATION_MYSERIALSERVER_H

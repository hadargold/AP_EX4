#include "TcpServer.h"

namespace server_side {

    //return new main socketId
    int TcpServer::listenToPort(int serverPort){

        int socketFd; // socket fileDescriptor

        struct sockaddr_in serv_addr;

        //creating socket object
        socketFd = socket(AF_INET, SOCK_STREAM, 0);
        //if creation failed
        if (socketFd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }


        //set accept timeout
        struct timeval tv;
        tv.tv_sec = 1;       /* Timeout in seconds */
        setsockopt(socketFd, SOL_SOCKET, SO_RCVTIMEO,(struct timeval *)&tv,sizeof(struct timeval));


        //Initialize socket structure
        bzero((char *) &serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET; // tcp server
        serv_addr.sin_addr.s_addr = INADDR_ANY; //server ip (0.0.0.0 for all incoming connections)
        serv_addr.sin_port = htons(serverPort); //init server port

        //bind the host address using bind() call
        if (bind(socketFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            //if binding faild
            perror("ERROR on binding");
            exit(1);
        }

        //start listening for the clients using the main socket
        listen(socketFd, 5);

        return socketFd;

    }



    int TcpServer::acceptConnection(int mainSocketId) {

        int clilen;
        struct sockaddr_in serv_addr, cli_addr;
        clilen = sizeof(cli_addr);
        int newsockfd; // new socket fileDescriptor

        //accept actual connection from the client
        newsockfd = accept(mainSocketId, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (newsockfd < 0){
            //the error is not timeout error
            if (errno != EWOULDBLOCK){

                throw "Socket closed or socket error!";

            }
        }


        return newsockfd;
    }

    std::string TcpServer::readLine(int socketId) {

        std::string dataStr;
        bool lineReaded = false;

        while (!lineReaded) {
            char buf[1];
            int numBytesRead = recv(socketId, buf, sizeof(buf), 0);
            if (numBytesRead > 0) {
                char c = buf[0];
                if (c == '\n') {
                    if (dataStr.length() > 0) {
                        //the all line readed, end while
                        lineReaded = true;
                    }
                } else dataStr += c;

            } else {

                //the error is not timeout error
                if (errno != EWOULDBLOCK){

                    throw "Socket closed or socket error!";

                }
            }
        }

        return dataStr;
    }

}

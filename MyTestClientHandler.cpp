//
// Created by yuval on 1/23/20.
//


#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include "MyTestClientHandler.h"
using namespace std;

void server_side::MyTestClientHandler::handleClient(int socket) {
    string problem = "";
    string ans;
    while (true) {
        char buf[1024];
        int numBytesRead = recv(socket, buf, sizeof(buf), 0);
        if (numBytesRead > 0) {
            for (int i = 0; i < numBytesRead; i++) {
                char c = buf[i];
                // if this is the end of the problem string
                if (c == '\n') {
                    if (problem.length() > 0) {
                        // if the client wrote "end" - close the socket
                        if (!problem.compare("end")) {
                            close(socket);
                            return;
                        }
                        if (cacheManager->isExistsInCache(problem)) {
                            ans = cacheManager->loadFromCache(problem);
                        } else {
                            ans = solver->solve(problem);
                            cacheManager->saveToCache(problem, ans);
                        }
                        ans = ans+"\n";
                        ssize_t n;

                        // Send message
//                        n = write(socket, ans.c_str(), ans.length());
//
//                        if (n < 0) {
//                            close(socket);
//                            return;
//                        }

                        problem = "";
                    }
                } else problem += c;
            }
        } else {
            if (errno == EWOULDBLOCK) {
                continue;
            }
            close(socket);
            return;
        }
    }
}
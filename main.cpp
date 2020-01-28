//
// Created by yuval on 1/23/20.
//

#include <vector>
#include <iostream>
#include <string>

#include "StringReverser.h"
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "FileCacheManager.h"
#include "SearchSolver.h"
#include "MyTestClientHandler.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "AStar.h"
#include "MyClientHandler.h"



using namespace server_side;

using std::fstream;
using std::vector;
using std::pair;
using std::to_string;

int main(int argc, char **argv) {

    if(argc < 1) throw "usage: <executable> <port>";
    int port = std::stoi(argv[1]);

    auto solver = new SearchSolver(new AStar());
    auto cacheManager = new FileCacheManager();

    IClientHandler* clientHandler = new MyClientHandler(solver, cacheManager);

    auto myServer = new server_side::MyParallelServer();

    myServer->open(port, clientHandler);

    delete solver;
    delete cacheManager;
    delete clientHandler;
    delete myServer;

    return 0;

}

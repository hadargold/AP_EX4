cmake_minimum_required(VERSION 3.12)
project(ServerApplication)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -lpthread")

add_executable(ServerApplication IServer.h MySerialServer.cpp
        MySerialServer.h IClientHandler.h MyTestClientHandler.h ISolver.h ICacheManager.h
        FileCacheManager.cpp FileCacheManager.h
        StringReverser.h TcpServer.cpp TcpServer.h main.cpp MyParallelServer.cpp MyParallelServer.h ISearchable.h ISearcher.h MyClientHandler.cpp MyClientHandler.h SearchSolver.h Matrix.cpp Matrix.h State.h DFS.cpp DFS.h BFS.cpp BFS.h BestFirstSearch.cpp BestFirstSearch.h AStar.cpp AStar.h PriorityQueue.h MySerialServer.h MySerialServer.cpp MyParallelServer.cpp MyParallelServer.h MyTestClientHandler.h StringReverser.h main.cpp PriorityQueue.h MyTestClientHandler.cpp)

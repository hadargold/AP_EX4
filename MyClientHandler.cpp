//
// Created by hadar on 1/21/20.
//
#include "MyClientHandler.h"
#include "SearchSolver.h"
#include "Matrix.h"


server_side::MyClientHandler::MyClientHandler(
        server_side::ISolver<server_side::ISearchable *, server_side::SearchAlgo> *solver,
        server_side::ICacheManager *cacheManager) : solver(solver), cacheManager(cacheManager) {}


void server_side::MyClientHandler::handleClient(int socketID) {

    string curLine;

    string allProb;

    vector<vector<int>> matrixInfo;

    while ("end"!= (curLine = TcpServer::readLine(socketID))){

        allProb += (curLine + "\n");

        std::string buff{""};
        std::vector<std::string> splitLine;
        const char splitChar = ',';
        for (auto n : curLine)
        {
            if (n != splitChar)
                buff += n;
            else if (n == splitChar && buff != "")
            {
                splitLine.push_back(buff);
                buff = "";
            }
        }
        if (buff != "")
            splitLine.push_back(buff);

        vector<int> row;

        for (auto const &cell : splitLine){
            row.push_back(std::stoi(cell));
        }

        matrixInfo.push_back(row);

    }

    pair<int, int> dst;
    pair<int, int> src;

    dst.first = matrixInfo.back().front();
    dst.second = matrixInfo.back().back();

    src.first = (matrixInfo.end() - 2)->front();
    src.second = (matrixInfo.end() - 2)->back();


    auto it = matrixInfo.begin();

    vector<vector<int>> matrix;

    for(; it != matrixInfo.end() - 2; it++)
        matrix.push_back(*it);

    auto graph = Matrix(matrix, src, dst);

    std::string solutionString;

    if (cacheManager->isExistsInCache(allProb)){
        solutionString = cacheManager->loadFromCache(allProb);
    } else {
        SearchAlgo result = solver->solve(&graph);
        solutionString = result.shortestPathRoute;
        cacheManager->saveToCache(allProb, solutionString);
    }

    TcpServer::writeToClient(socketID, solutionString);
}

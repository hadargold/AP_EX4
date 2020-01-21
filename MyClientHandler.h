#ifndef SERVERAPPLICATION_MYCLIENTHANDLER_H
#define SERVERAPPLICATION_MYCLIENTHANDLER_H

#include "IClientHandler.h"
#include "ISolver.h"
#include "ICacheManager.h"
#include "TcpServer.h"
#include "Utils.h"
#include "ISearchable.h"
#include "ISearcher.h"

#define END "end"
#define CELL_SPLIT_CHAR ','

using std::string;
using std::vector;
using std::pair;

namespace server_side{

    class MyClientHandler : public IClientHandler {

        ISolver<ISearchable *, SearchAlgo> *solver;
        ICacheManager *cacheManager;

    public:

        MyClientHandler(ISolver<ISearchable *, SearchAlgo> *solver, ICacheManager *cacheManager);

        void handleClient(int socketID) override;

    };
}

#endif //SERVERAPPLICATION_MYCLIENTHANDLER_H

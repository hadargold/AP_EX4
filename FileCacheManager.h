#ifndef SERVERAPPLICATION_FILECACHEMANAGER_H
#define SERVERAPPLICATION_FILECACHEMANAGER_H

#include <map>
#include <mutex>

#include "ICacheManager.h"
#define CACHE "cache_file.txt"
#define SPLIT_CHAR '$'

namespace server_side{

    class FileCacheManager : public ICacheManager {

        std::mutex mut;

    public:

        bool isExistsInCache(std::string key) override;

        std::string loadFromCache(std::string key) override;

        void saveToCache(std::string key, std::string solution) override;

        // appends to a given file name. creates him if he haven't been created yet

        static void appendToFile(std::string fileName, std::string dataToAppend){
            std::fstream stream;
            stream.open(fileName, std::ios::app | std::ios::ate);

            stream << dataToAppend;

            stream.flush();
            stream.close();
        };

    };
}

#endif //SERVERAPPLICATION_FILECACHEMANAGER_H

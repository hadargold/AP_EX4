
#include <fstream>
#include "FileCacheManager.h"

bool server_side::FileCacheManager::isExistsInCache(std::string key) {

    try {
        loadFromCache(key);
        return true;
    }catch (...){ // no file exist or key doesnt exists in cache
        return false;
    }
}

std::string server_side::FileCacheManager::loadFromCache(std::string key) {

    mut.lock();

    std::string fileContent = ICacheManager::readAllFileContent(CACHE);

    std::vector<std::string> afterSplit = ICacheManager::explode(fileContent, SPLIT_CHAR);

    std::map<std::string, std::string> cacheMap;

    auto it = afterSplit.begin();

    for(;it != afterSplit.end(); it += 2 ) {
        std::string currKey = *it;
        std::string currValue = *(it + 1);
        cacheMap.insert(std::pair<std::string, std::string>(currKey, currValue));

    }

    auto valueIterator = cacheMap.find(key);

    mut.unlock();

    //iterator will be the end if key doesnt exists
    if(valueIterator != cacheMap.end()){
        return valueIterator->second;
    } else {
        throw "key does not exist in cache! check for existence first";
    }
}


void server_side::FileCacheManager::saveToCache(std::string key, std::string solution) {

    mut.lock();

    std::string dataToSave = key + SPLIT_CHAR + solution + SPLIT_CHAR;

    FileCacheManager::appendToFile(CACHE, dataToSave);

    mut.unlock();

}

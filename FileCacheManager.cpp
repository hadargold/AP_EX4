//
// Created by yuval on 1/23/20.
//
#include <fstream>
#include <cstring>
#include "FileCacheManager.h"
using namespace std;

bool server_side::FileCacheManager::isExistsInCache(std::string key) {

    try {
        loadFromCache(key);
        return true;
    }catch (...){
        return false;
    }
}

std::string server_side::FileCacheManager::loadFromCache(std::string key) {

    mut.lock();
    ifstream t("cache.txt");
    string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    char* input = (char*) str.c_str();
    char *token = std::strtok(input, "$");
    std::vector<string> splitValue;

    while (token != NULL) {
        splitValue.emplace_back(token);
        token = std::strtok(NULL, "$");
    }
    map<string, string> cacheMap;
    for(std::size_t i =0 ; i < splitValue.size() ; i = i+2){
        std::string currKey =  splitValue[i];
        std::string currValue =  splitValue[i+1];
        cacheMap.insert(std::pair<std::string, std::string>(currKey, currValue));
    }

    auto valueIterator = cacheMap.find(key);

    mut.unlock();
    if(valueIterator != cacheMap.end()){
        return valueIterator->second;
    } else {
        throw "key does not exist in cache";
    }
}


void server_side::FileCacheManager::saveToCache(std::string key, std::string solution) {
    const char splitChar ='$';
    mut.lock();

    std::string dataToSave = key + splitChar + solution + splitChar;

    FileCacheManager::appendToFile("cache.txt", dataToSave);

    mut.unlock();

}

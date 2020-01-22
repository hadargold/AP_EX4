#ifndef SERVERAPPLICATION_ICACHEMANAGER_H
#define SERVERAPPLICATION_ICACHEMANAGER_H

#include <string>
#include <vector>
#include <fstream>

namespace server_side {

    class ICacheManager {

    public:

        //my assumption of methods
        virtual bool isExistsInCache(std::string key) = 0;

        virtual std::string loadFromCache(std::string key) = 0;

        virtual void saveToCache(std::string key, std::string solution) = 0;

        // reads all file content to a string
        static std::string readAllFileContent(std::string fileName){
            std::ifstream t(fileName);
            std::string str((std::istreambuf_iterator<char>(t)),
                            std::istreambuf_iterator<char>());

            return str;
        };

        // splits string based on given char

        static const std::vector<std::string> explode(std::string &s, const char &c)
        {
            std::string buff{""};
            std::vector<std::string> v;

            for (auto n : s)
            {
                if (n != c)
                    buff += n;
                else if (n == c && buff != "")
                {
                    v.push_back(buff);
                    buff = "";
                }
            }
            if (buff != "")
                v.push_back(buff);

            return v;
        };
    };
}


#endif //SERVERAPPLICATION_ICACHEMANAGER_H

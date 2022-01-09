#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <fstream>
#include <sstream>

namespace json {
    bool isNum(char c) {
        return strContains("0123456789.", c);
    }

    bool firstAndLastMatch(std::string str, char first, char last){
        return str[0] == first && str[str.length() - 1] == last;
    }

    bool strContains(std::string str, char c) {
        return str.find(c) != std::string::npos;
    }

    bool isEmpty(char c){
        return c == ' ' || c == '\n' || c == '\t';
    }

    static bool writeFile(const char* filename, std::string content){
        std::ofstream file(filename);

        if (file.is_open()) {
            file << content;
            file.close();
            return true;
        }

        return false;
    }

    static std::string readFile(const char* filename){
        std::ifstream file(filename);
        std::string ret = "";

        if(file.is_open()){
            std::stringstream sstream;
            sstream << file.rdbuf();
            ret = sstream.str();
        }
    }
}

#endif
#ifndef STRINGOPERATIONS_H
#define STRINGOPERATIONS_H

#include <vector>
#include <string>

class StringOperations{
public:
    std::vector<std::string> split (std::string s, char delimiter);
    void trimRight(std::string &str);
};

#endif
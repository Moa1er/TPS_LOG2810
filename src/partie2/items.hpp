/******************************************
Mohamed Fenjiro <mohamed.fenjiro@polymtl.ca>
 ******************************************/

#include "node.hpp"

class Items : public Node{
public:
    Items();
    ~Items();
    void setName(char name);
    void setId(char id);
    void setType(char type);
    char getName();
    char getId();
    char getType();

private:
    char name;
    char id;
    char type;
};
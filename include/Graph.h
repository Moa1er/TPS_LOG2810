#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <utility>
#include <vector>
#include "../include/Personne.h"


class Graph{
private:
    int nbVertices_;
    std::list<std::pair<int, double>> *adjecencyList_;
    std::vector<double> djikstraOutput_;

public:
    Graph() = default;

    void addEdge(int v1, int v2, double weight);
    std::vector<double> shortestPath(int startNode);
    void printGraph(std::vector<Personne> personnes);

    void setNbVectices(int nbVertices){nbVertices_ = nbVertices;};
    void setList(int nbVertices);
    void setDjikstraOutput(std::vector<double> djiOutput){djikstraOutput_ = djiOutput;};

    std::vector<double> getDjikstraOut(){return djikstraOutput_;};
};



#endif
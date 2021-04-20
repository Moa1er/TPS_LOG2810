#include <iostream>
#include <set>
#include <vector>

#include "../include/Graph.h"

using namespace std;

#define INF 1000000

void Graph::setList(int nbVertices){
    adjecencyList_ = new list<pair<int, double>>[nbVertices];
}

void Graph::addEdge(int node1, int node2, double weight){
    adjecencyList_[node1].push_back(make_pair(node2, weight));
}

vector<double> Graph::shortestPath(int startNode){
    set<pair<double, int>> extract_set;

    vector<double> distances(nbVertices_, INF);

    extract_set.insert(make_pair(0, startNode));
    distances[startNode] = 0;

    //until the end of the nodes
    while(!extract_set.empty()){
        pair<double, int> tmp = *(extract_set.begin());
        extract_set.erase(extract_set.begin());

        // Get the vertex number
        int firstVertexIndex = tmp.second;

        for(auto i = adjecencyList_[firstVertexIndex].begin(); i != adjecencyList_[firstVertexIndex].end(); i++){
            int secondVertexIndex = (*i).first;
            double weight = (*i).second;

            if(distances[secondVertexIndex] > distances[firstVertexIndex] + weight){

                // if already in set we remove it
                if(distances[secondVertexIndex] != INF){
                    extract_set.erase(extract_set.find(make_pair(distances[secondVertexIndex], secondVertexIndex)));
                }

                //update distance
                distances[secondVertexIndex] = distances[firstVertexIndex] + weight;
                extract_set.insert(make_pair(distances[secondVertexIndex], secondVertexIndex));
            }
        }
    }
    return distances;
}

void Graph::printGraph(vector<Personne> personnes){
    cout << endl;
    for(int i = 0; i < nbVertices_; i++){
        for(auto elementListe : adjecencyList_[i]){
            cout << "(" << personnes[i].name_
                 << " " << personnes[elementListe.first].name_
                 << " (" << elementListe.second << "))" 
                 << endl;
        }
    }    
}
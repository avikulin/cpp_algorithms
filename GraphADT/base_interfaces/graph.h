#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

#include "../iterators/base_iterator.h"

using namespace std;

struct Edge{
    int u, v;
};

class Graph{

friend BaseIterator;

private:
     map<int, list<int>> adj_list;

public:
    BaseIterator begin();
    BaseIterator end();

    const BaseIterator begin() const;
    const BaseIterator end() const;

    Graph() = delete ;
    Graph(bool directed, size_t VertexCount);
    void InsertEdge(const Edge& e);
    void RemoveEdge(const Edge& e);
    bool CheckEdgeExists(const Edge& e) const;
};

#endif // GRAPH_H

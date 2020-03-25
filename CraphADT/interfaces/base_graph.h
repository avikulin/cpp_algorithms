#ifndef BASE_GRAPH_H
#define BASE_GRAPH_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory>

#include "base_vertex.h"

using namespace std;

class base_graph
{
private:
    map<shared_ptr<BaseVertex>, vector<shared_ptr<BaseVertex>>> adj_list;
    map<shared_ptr<BaseVertex>, set<shared_ptr<BaseVertex>>> adj_set;

public:
    base_graph() = delete ;
    base_graph(int id);

    int GetID() const;
    void AddEdge(BaseVertex u,BaseVertex v);
    void RemoveEdge(BaseVertex u,BaseVertex v);
    void PrintToConsole() const;
};

#endif // BASE_GRAPH_H

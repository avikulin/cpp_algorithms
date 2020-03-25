#ifndef BASE_EDGE_H
#define BASE_EDGE_H

#include <iostream>
#include <memory>
#include <base_vertex.h>

using namespace std;

class base_edge
{
private:
    shared_ptr<BaseVertex> pointA;
    shared_ptr<BaseVertex> pointB;
    int weight;
public:
    base_edge() = delete ;
    base_edge(int id, shared_ptr<BaseVertex> u, shared_ptr<BaseVertex> v);
    base_edge(int id, int weight, shared_ptr<BaseVertex> u, shared_ptr<BaseVertex> v);
    bool has_vertex(weak_ptr<BaseVertex> vertex);
    shared_ptr<BaseVertex> get_opposite(weak_ptr<BaseVertex> vertex);
};

#endif // BASE_EDGE_H

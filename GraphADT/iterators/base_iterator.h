#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include <memory>

#include "../base_interfaces/graph.h"

using namespace std;

class BaseIterator {
    friend Graph;
private:
    unique_ptr<Graph> _pgraph;
public:
    typedef forward_iterator_tag iterator_category;
    typedef int value_type;
    typedef int* pointer;
    typedef int difference_type;

    BaseIterator (unique_ptr<Graph> pGraph);
    virtual ~BaseIterator();

    virtual int begin();
    virtual bool end();
    int next();
};

#endif // BASE_ITERATOR_H

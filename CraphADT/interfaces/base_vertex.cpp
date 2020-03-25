#include "base_vertex.h"

BaseVertex::BaseVertex(int id)
{
    this->_id = id;
}

BaseVertex::BaseVertex(int id, int category)
{
    this->_id = id;
    this->_category = category;
}

int BaseVertex::GetID()
{
    return this->_id;
}

int BaseVertex::GetCategory()
{
    return this->_category;
}

void BaseVertex::SetCategory(int category)
{
    this->_category = category;
}

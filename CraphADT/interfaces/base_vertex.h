#ifndef VERTEX_H
#define VERTEX_H


class BaseVertex
{
   private:
        int _id = -1;
        int _category = -1;
    public:
        BaseVertex() = delete;
        BaseVertex(int id);
        BaseVertex(int id, int category);

        int GetID();

        int GetCategory();
        void SetCategory(int category);
};

#endif // VERTEX_H

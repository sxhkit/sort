#pragma once
#include "stdio.h"
#include <vector>
typedef struct QElement
{
    int priority;
    int data;

    QElement()
    {
        priority = 0;
        data = -1;
    }

    bool operator ==(QElement el)
    {
        return (priority == el.priority &&
            data == el.data);
    }

    QElement & operator=(QElement el){
        priority = el.priority;
        data = el.data;
        return *this;
    }
}QElement;

class PriorityQ
{
public:
    PriorityQ();
    ~PriorityQ();

    void push_back(int data);
    QElement maximum();
    void insert(QElement e);
    bool pop(QElement &e);
private:
    void modify_heap(int i,int size);
private:
    std::vector<QElement> _vector;
};

void testPriority();
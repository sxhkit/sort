#include "PriorityQueue.h"
PriorityQ::PriorityQ()
{
}

PriorityQ::~PriorityQ()
{

}

void PriorityQ::insert(QElement e)
{
    if (_vector.size() <= 0 )
    {
        _vector.push_back(e);
        return;
    }
    QElement first = _vector[0];
    if (e.priority > first.priority)
    {
        printf("insert the highest priority element !");
    }
    //_vector[_vector.size()] = e;
    _vector.push_back(e);
    int pos = _vector.size() - 1;
    int par = (pos-1) / 2;
    while (_vector[pos].priority < _vector[par].priority)
    {
        QElement t = _vector[par];
        _vector[par] = _vector[pos];
        _vector[pos] = t;
        pos = par;
        par = (pos - 1) / 2;
    }

}

QElement PriorityQ::maximum()
{
    return _vector[0];
}

bool PriorityQ::pop(QElement &e)
{
    if (_vector.size() <= 0 )
    {
        return false;
    }
    e = _vector[0];
    int len = _vector.size();
    _vector[0] = _vector[len - 1];
    _vector[len - 1] = e;
    modify_heap(0,len - 1);
    /*
    *  最好的是通过修改堆之前pop出最后一个,次数放在后面是为了通过 size 大小来控制 为了与 算饭导论 思想一直，通过堆的大小来控制 ，而非使用vector 可以直接弹出
    */
    _vector.pop_back();
    return true;
}

void PriorityQ::push_back(int data)
{
    QElement e;
    e.data = data;
    e.priority = -1;
    int len = _vector.size();
    _vector[len] = e;
}

void PriorityQ::modify_heap(int i,int size)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && _vector[i].priority > _vector[left].priority)
    {
        smallest = left;
    }

    if (right < size && _vector[right].priority < _vector[smallest].priority)
    {
        smallest = right;
    }
    if (smallest!= i)
    {
        QElement max = _vector[smallest];
        _vector[smallest] = _vector[i];
        _vector[i] = max;
        modify_heap(smallest,size);
    }
}

void testPriority()
{
    PriorityQ p;
    int a[] = { 2, 5, 3, 9, 7, 12, 8, 6 };
    int len = sizeof(a) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        QElement e;
        e.data = a[i];
        e.priority = len - i;
        p.insert(e);
    }

    QElement e;
    while (p.pop(e))
    {
        printf("priority = %d,data=%d \n", e.priority, e.data);
    }
    int a_ = 0;
}
#ifndef PRIORITY_H
#define PRIORITY_H

template <class T>
class priority_queue{
public:
    void Insert(T toAdd);
    T GetNext();
    T* Peek();
    bool IsEmpty();
    int Size();
private:
    int size;
};

#endif PRIORITY_H

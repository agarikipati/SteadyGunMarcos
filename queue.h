#ifndef QUEUE_H
#define QUEUE_H

#ifndef NULL
#define NULL 0
#endif

template <class T>
struct node{
    node<T>* next;
    T item;
    node(){
	next = NULL;
    }
    node(T &foo){
	next = NULL;
	item = foo;
    }
};

template <class T>
class queue{
public:
    queue();
    T& Peek();
    void Enqueue(T &toAdd);
    T Dequeue();
    int Size();
private:
    node<T>* front;
    node<T>* last;
    int size;
};

#endif

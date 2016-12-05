#include "queue.h"

template <class T>
queue<T>::queue(){
    front = last = NULL;
    size = 0;
}

template <class T>
queue<T>::~queue(){
    node<T>* crawler = front;
    while (crawler != NULL){
	node<T>* tmp = crawler;
	crawler = crawler->next;
	delete tmp;
    }
}

template <class T>
T& queue<T>::Peek(){
    if (front == NULL){
	throw "queue empty";
    }
    return front->item;
}

template <class T>
void queue<T>::Enqueue(T &toAdd){
    node<T>* new_guy = new node<T>(toAdd);
    size++;
    if (last == NULL){
	first = last = new_guy;
	return;
    }
    last->next = new_guy;
    last = new_guy;
}

template <class T>
T queue<T>::Dequeue(){
    if (front == NULL){
	throw "underflow";
    }
    T foo = front->item;
    node<T>* tmp = front;
    if (front == last){
	front = last = NULL;
    }
    else{
	front = front->next;
    }
    delete tmp;
    return foo;
}

template <class T>
int queue<T>::Size(){
    return size;
}

#ifndef PRIORITY_H
#define PRIORITY_H

template <class T>
class priority_queue{
public:
    priority_queue();
    void Insert(T toAdd);
    T GetNext();
    T& Peek();
    bool IsEmpty();
    int Size();
private:
    int Parent(int index);
    int Left(int index);
    int Right(int index);
    void Heapify(int index);
    void BuildHeap();
    bool IsHeap(int index);
    int size;
    dynamicArray<T> objects;
};

template <class T>
priority_queue<T>::priority_queue(){
    size = 0;
}

template <class T>
void priority_queue<T>::Insert(T toAdd){
    objects.addElement(toAdd);
    size++;
    int curr_index = size - 1;
    int parent = Parent(curr_index);
    while (parent >= 0 && objects[curr_index] < objects[parent]){
	T tmp = objects[parent];
	objects[parent] = objects[curr_index];
	objects[curr_index] = tmp;
	curr_index = parent;
	parent = Parent(curr_index);
    }
}

template <class T>
T GetNext(){
    if (size == 0){
	throw "queue empty";
    }
    T min = objects[0];
    objects[0] = objects[size - 1];
    size--;
    Heapify(0);
    return min;
}

template <class T>
T& Peek(){
    if(size == 0){
	throw "queue empty";
    }
    return objects[0];
}

template <class T>
bool priority_queue<T>::IsEmpty(){
    return size == 0;
}

template <class T>
int priority_queue<T>::Size(){
    return size;
}

template <class T>
void priority_queue<T>::Insert(T toAdd){
    
}

template <class T>
int priority_queue<T>::Parent(int index){
    return (index - 1) / 2;
}

template <class T>
int priority_queue<T>::Left(int index){
    return 2*index + 1;
}

template <class T>
int priority_queue<T>::Right(int index){
    return 2*index + 2;
}

template <class T>
void priority_queue<T>::Heapify(int index){
    int min = index;
    int left = Left(index);
    int right = Right(index);
    if (left < size && objects[left] < objects[min]){
	min = left;
    }
    if (right < size && objects[right] < objects[min]){
	min = right;
    }
    if (min != index){
	T tmp = objects[index];
	objects[index] = objects[min];
	objects[min] = tmp;
	Heapify(min);
    }
}

template <class T>
void priority_queue<T>::BuildHeap(){
    for (int i = size / 2 - 1; i >= 0; i--){
	Heapify(i);
    }
}

template <class T>
bool priority_queue<T>::IsHeap(int index){
    bool left_valid = true;
    bool right_valid = true;
    int left = Left(index);
    int right = Right(index);
    if (left < size){
	if (objects[left] < objects[index]){
	    return false;
	}
	left_valid = IsHeap(left);
    }
    if (right < size){
	if (objects[right] < objects[index]){
	    return false;
	}
	right_valid = IsHeap(right);
    }
    return (left_valid && right_valid);
}

#endif PRIORITY_H

#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H

#include <cstddef>
#include <iostream>
#include <string>

#ifndef NULL
#define NULL 0
#endif

template <class T>
class dynamicArray{
	static const int MAX_SIZE = 3000000 / sizeof(T);
public:
	dynamicArray();
	dynamicArray(const dynamicArray<T> &toCopy);
	~dynamicArray();
	T& operator[] (const int index);
	void addElement(T toAdd);
	bool deleteElement(T toDelete);
	void removeLast();
	int size() const;
	int count() const;
	float util() const;
	void shrink();
	void print();
private:
	T* elements;
	int elementsSize;
	int lastIndex;
	void increaseSize(int additional);
	void copyArr(T* toGive, T* toReceive, int num);
	void removeIndex(int index);
	void fillElements(int startIndex, int stopIndex, T val);
};

#include "dynamicarray.cpp"

#endif

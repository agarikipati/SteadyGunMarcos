template <class T>
dynamicArray<T>::dynamicArray(){
	this->elements = NULL;
	this->elementsSize = 0;
	lastIndex = -1;
}

template <class T>
dynamicArray<T>::dynamicArray(const dynamicArray<T> &toCopy){
	elements = toCopy.elements;
	elementsSize = toCopy.elementsSize;
	lastIndex = toCopy.lastIndex;
}

template <class T>
dynamicArray<T>::~dynamicArray(){
	if(elements != NULL){
		delete[] elements;
		elements = NULL;
	}
}

template <class T>
T& dynamicArray<T>::operator[] (const int index){
    return elements[index];
}

template <class T>
void dynamicArray<T>::increaseSize(int additional){	
	T* newElements = new T[elementsSize + additional];
	copyArr(elements, newElements, lastIndex + 1);
	elementsSize = elementsSize + additional;
	delete [] elements;
	elements = newElements;
}

template <class T>
void dynamicArray<T>::addElement(T toAdd){
	if(lastIndex + 1 < elementsSize){
		elements[++lastIndex] = toAdd;	
		return;
	}
	if(elementsSize > MAX_SIZE){
		throw "Array full";	
	}
	int increase = ((elementsSize > 10) ? elementsSize : 10);	
	if(elementsSize + increase > MAX_SIZE){
		increaseSize(MAX_SIZE - elementsSize);	
	}
	else{
		increaseSize((elementsSize > 10) ? elementsSize : 10);
	}
	elements[++lastIndex] = toAdd;
}

template <class T>
bool dynamicArray<T>::deleteElement(T toDelete){
	try{
		bool elementInArr = false;
		for(int i = 0; i <= lastIndex; i++){
			if(elements[i] == toDelete){
				if(!elementInArr){
					elementInArr = true;
				}
				removeIndex(i);	
				i--; //To correct for shifting elements
			}
		}
		return elementInArr;

	}catch(const char* msg){
		throw msg;	
	}
}

template <class T>
void dynamicArray<T>::removeLast(){
    if(lastIndex < 0){
	throw "array empty";
    }
    lastIndex--;
}

template <class T>
int dynamicArray<T>::size() const{
	return elementsSize;	
}

template <class T>
int dynamicArray<T>::count() const{
	return lastIndex + 1;
}

template <class T>
float dynamicArray<T>::util() const{
	if(count() == 0){
		throw "Count is zero, util is undefined";	
	}
	return float(size()) / count();
}

template <class T>
void dynamicArray<T>::shrink(){
	if(elementsSize == lastIndex + 1){
		return;	
	}
	T* newElements = new T[lastIndex + 1];
	copyArr(elements, newElements, lastIndex + 1);	
	delete [] elements;
	elements = newElements;
	elementsSize = lastIndex + 1;
}

template <class T>
void dynamicArray<T>::copyArr(T* toGive, T* toReceive, int num){
	for(int i = 0; i < num; i++){
		toReceive[i] = toGive[i];	
	}
}

template <class T>
void dynamicArray<T>::removeIndex(int index){
	if(index >= elementsSize || index < 0){
		throw "Invalid delete: Index out off range";	
	}
	for(int i = index; i <= lastIndex - 1; i++){
		elements[i] = elements[i + 1];	
	}
	lastIndex--;
}

template <class T>
void dynamicArray<T>::fillElements(int startIndex, int stopIndex, T val){
	for(int i = startIndex; i <= stopIndex; i++){
		elements[i] = val;	
	}
}

template <class T>
void dynamicArray<T>::print(){
	for(int i = 0; i <= lastIndex; i++){
	    std::cout << "Index: " << i << " "; 
	    std::cout << "| Data: " << elements[i];	
	    std::cout << std::endl;
	}
}

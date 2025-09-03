template <typename T>
ArrayList<T>::ArrayList(int i) {
    // TODO
    if(i <= 0)
    {
        throw string("size has to be positive!");
    }
    maxSize = i;
    buffer = new T[maxSize];
    this->length = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    // TODO
    if(isFull())
    {
        throw string("append: error, List is full!");
    }
    buffer[this->length] = elem;
    this->length++;



}

template <typename T>
void ArrayList<T>::clear() {
    // TODO
    this->length = 0;

}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    // TODO

    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for(int i = 0; i < this->length; i++)
    {
        buffer[i] = copyObj.buffer[i];
    }

}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    // TODO
    if(position < 0 || position >= this->length)
    {
        throw string("getElement: error, position out of bounds");
    }

    return buffer[position]; 
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    // TODO
    if(isFull())
    {
        throw string("insert: error, list is full!");
    }
    if(position < 0 || position > this->length)
    {
        throw string("insert: error, position out of bounds");
    }
    for(int i = this->length; i > position; i--)
    {
        buffer[i] = buffer[i-1];
    }

    buffer[position] = elem;
    this->length++;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    // TODO
    if(position < 0 || position >= this->length)
    {
        throw string("remove: error, position out of bounds");
    }
    for(int i = position; i < this->length-1; i++)
    {
        buffer[i] = buffer[i+1];
    }
    this->length--;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    // TODO
    if(position < 0 || position >= this->length)
    {
        throw string("replace: error, position out of bounds"); 
    }
    buffer[position] = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }

    return outStream;
}

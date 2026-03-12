template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    if (i <= 0) {
        maxSize = 1;
    } else {
        maxSize = i;
    }

    buffer = new T[maxSize];  // allocate array of T
    length = -1;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = nullptr;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    length = copyObj.length;

    buffer = new T[maxSize];

    for (int i = 0; i <= length; i++){
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    if(length < 0){
        throw "No Elements";
    }
    return buffer[length];
    // TODO
}

template <typename T>
void ArrayStack<T>::pop() {
    if(length < 0){
        throw "No Elements";
    }
    length --;
    // TODO
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if(length+1 > maxSize){
        throw "Too Many Elements";
    }
    length++;
    buffer[length] = elem;

}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (length < 0){
       throw "No Elements";
    }
    if (length == 0){
        return;
    }
    if (dir == Stack<T>::LEFT){
        T temp = buffer[0];
        for (int i = 0; i < length; i++){
            buffer[i] = buffer[i+1];
        }
        buffer[length] = temp;
    }
    else{
        T temp = buffer[length];
        for (int i = length; i > 0; i--){
            buffer[i] = buffer[i-1];
        }
        buffer[0] = temp;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "length\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

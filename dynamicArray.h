#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

//#include "boat.h"

template <class T>
class DynamicArray {
    protected:
        T* array;
        int maxSize, currentSize;
    public:
        DynamicArray<T>(){
            maxSize = 10; //arbitrary value
            currentSize = 0;
            array = new T[maxSize];
        }

        DynamicArray<T>(T* a, int m, int c){
            maxSize = m;
            currentSize = c;
            array = new T[maxSize];
            for(int i = 0; i < currentSize; i++){
                array[i] = a[i];
            }
        }

        DynamicArray<T>(const DynamicArray<T>& rhs){
            maxSize = rhs.maxSize;
            currentSize = rhs.currentSize;
            array = new T[maxSize];
            for(int i = 0; i < currentSize; i++){
                array[i] = rhs.array[i];
            }
        }

        ~DynamicArray<T>(){
            delete[] array;
        }

        DynamicArray<T>& operator=(const DynamicArray<T>& rhs){
            maxSize = rhs.maxSize;
            currentSize = rhs.currentSize;
            array = new T[maxSize];
            for(int i = 0; i < currentSize; i++){
                array[i] = rhs.array[i];
            }
            return *this;
        }

        int getMaxSize(){
            return maxSize;
        }

        int getCurrentSize(){
            return currentSize;
        }

        T* getArray(){
            return array;
        }

        void addItemToArray(T item){
            if(currentSize == maxSize){
                resizeArray();
            }
            array[currentSize] = item;
            currentSize++;
        }

        void resizeArray(){
            maxSize += 10; //arbitrary value
            T* temp = new T[maxSize];
            for(int i = 0; i < currentSize; i++){
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }

        T getElement(int ind){
            if(index <= currentSize){
                return array[index - 1]; //think it has to be -1
            }
            cout << "Error. The element you are trying to access is greater than the current size." << endl;
            //return 0; ?
        }

        void clearArray(){
            delete[] array;
            currentSize = 0;
            maxSize = 3;
            array = new T[maxSize];
            //think thats how to do it
        }
};

#endif
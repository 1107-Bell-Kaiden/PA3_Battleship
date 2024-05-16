#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
    protected:
        T* array;
        int maxSize, currentSize;
    public:
        DynamicArray<T>(){
            maxSize = 5; //arbitrary value
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

        int getMaxSize() const{
            return maxSize;
        }

        int getCurrentSize() const{
            return currentSize;
        }

        T* getArray() const{
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
            maxSize += 5; //arbitrary value
            T* temp = new T[maxSize];
            for(int i = 0; i < currentSize; i++){
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }

        T getElement(int ind) const{
            if(ind < currentSize){
                return array[ind]; //Doesnt have to be -1 since we're indexing zero based.
            } else {
                cout << "Error. The element you are trying to access is greater than the current size: " << currentSize << endl;
            }
            return T();
        }

        void changeElement(int ind, T chng){ //Fixed it
            if(ind < currentSize && ind >= 0){
                array[ind] = chng;
            } else {
                cout << "Error updating Element. The element you are trying to access is greater than the current size: " << currentSize << endl;
            }
            return;
        }

        void clearArray(){
            delete[] array;
            currentSize = 0;
            maxSize = 3;
            array = new T[maxSize];
            //think thats how to do it
        }

        void removeElement(){

        }

        void fill(T defaultVal) {
            if (currentSize < 100) {
                delete[] array;
                maxSize = 100;
                array = new T[maxSize];
                currentSize = 100;
            }
            for(int i = 0; i < currentSize; i++){
                array[i] = defaultVal;
            }
        }

};

#endif
#include <iostream>
using namespace std;



class DynamicArray {
private:
    int *data;
    int size;
    int capacity;
public:
    DynamicArray(int capacity = 3) {
        data = new int[1];
        size = 0;
        this->capacity = capacity ;
    }
    int getSize() {
        return size;
    }
    int getCapacity() {
        return capacity;
    }

    void add(int element) {
        if (size == capacity) {
            make_new_array(2 * capacity);

        }

        data[size] = element;
        size++;
        cout << "size:" << size << '\n';
    }

    void make_new_array(int new_capacity) {
        cout << "Making new array with capacity " << new_capacity << endl;
        int *newData = new int[new_capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
        delete[] data;
        data = newData;
        capacity = new_capacity;
    }
};




//void deleteArray(int *arr)
//{
//    delete []arr;
//}
//
////void func to copy elements from array[int] to another array[int] with pointers
//void copy(int *arr1, int *arr2, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        arr2[i] = arr1[i];
//    }
//
//}
//
//
//void dynamicArray(int *arr, int size) {
//    for (int i = 0; i < size; i++) {
//        arr[i] = i;
//    }
//}

int main() {
    int capacity_user{0};
    cout <<  "Enter capacity of array: " ;
    cin >> capacity_user;
    DynamicArray arr(capacity_user);
    cout <<  "Size of array: "  << arr.getSize() << endl;
    cout <<  "Capacity of array: "  << arr.getCapacity() << endl;
    for (int i = 0; i < 100; ++i) {
        cout << "Enter element: " ;
        cin >> capacity_user;
        arr.add(capacity_user);
        if (capacity_user==100) {
            break;
        }
    }
    return 0;
}

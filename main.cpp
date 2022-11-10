
#include <iostream>

using namespace std;


template<class Type> class QueueType{
public:
    bool isEmptyQueue(){
        return count==0;
    };
    bool isFullQueue(){
        return count==maxQueueSize;
    };
    void initializeQueue(){

    };
    Type front(){

    };
    Type back(){};
    void addQueue(Type& queueElement){
        if(!isFullQueue()){
            queueRear = (queueRear + 1) % maxQueueSize;
            count++;
            list[queueRear]  = queueElement;
        }else{
            cout << "Cannot add to a full queue." << "\n";
            throw runtime_error("queue is full");
        }
    };
    void deleteQueue(){
        if(!isFullQueue()){
            count--;
            queueFront =(queueFront+1) % maxQueueSize;
        }else{
            cout << "Cannot remove from an empty queue" << '\n';
        }
    };

    QueueType(int queueSize = 100){
        if(queueSize<=0){
            cout << "Size can't be negative \n";
            throw (runtime_error("size is negative"));
        }
        list = new Type[queueSize];
        maxQueueSize = queueSize;

        queueFront =0;
        queueRear = maxQueueSize-1;
        count=0;






    }; // Function with default parameters
    QueueType(const QueueType&amp; otherQueue){ // To create a Queue object that copies another queue
    };

    ~QueueType(){
        delete[]list;
    };
private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    Type *list;
};



int main() {

    return 0;
}


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
    void initializeQueue(int maxQueueSize){
            queueFront = 0;
            queueRear = maxQueueSize - 1;
            count = 0;
        };
    Type front(){
        if (!isEmptyQueue())
        {
            return list[queueFront];
        }throw runtime_error("is empty");
        

    };
    Type back(){
        if (!isFullQueue())
        {
            return list[queueRear];
        }
        throw runtime_error("is full");
        
    };

    void addQueue(Type queueElement){
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
    QueueType(QueueType<Type>& otherQueue){ // To create a Queue object that copies another queue
        initializeQueue(otherQueue.maxQueueSize);
        maxQueueSize = otherQueue.maxQueueSize;
        if(!isEmptyQueue()){
           Type temp = otherQueue.queueFront;
           while (temp != otherQueue.queueRear)
           {
            addQueue(otherQueue.list[temp]);
            temp = (temp+1) % otherQueue.maxQueueSize;
           }
        }
        
    };

    ~QueueType(){
        delete[]list;
    };

    void print(){
        for (Type i = queueFront; i < maxQueueSize; i++) {
            if(list[i]!=0)
            cout << list[i] << " ";
        }
        
    }
private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    Type *list;
};



int main() {
    
    QueueType<int> q;
    q.initializeQueue(100);
    q.addQueue(2);
    q.addQueue(2);
    q.addQueue(8);

    q.addQueue(3);
    q.addQueue(73);
    q.deleteQueue();
    q.print();
     

    QueueType<int>q2(q);

    q2.print();






    return 0;
}

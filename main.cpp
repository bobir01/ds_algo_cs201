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
            queueFront = 1;
            queueRear = 0;
            count = 0;
            this->maxQueueSize = maxQueueSize;
           list = new Type[maxQueueSize];
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


        if (!isFullQueue()) {

            queueRear = (queueRear + 1) % maxQueueSize;
            count++;
            list[queueRear] = queueElement;
        } else throw runtime_error("queue is full");
    }

    void deleteQueue(){
        if(!isFullQueue()){
            count--;
            queueFront =(queueFront+1) % maxQueueSize;
        }else{
            cout << "Cannot remove from an empty queue" << '\n';
        }
    };

    explicit QueueType(int queueSize = 100){
        if(queueSize<=0){
            cout << "Size can't be negative \n";
            throw (runtime_error("size is negative"));
        }
        list = new Type[queueSize];
        maxQueueSize = queueSize;

        queueFront  = 1;
        queueRear = 0;

        count=0;

    }; // Function with default parameters

    QueueType( const QueueType<Type>& otherQueue) {
        initializeQueue();
        maxQueueSize = otherQueue.maxQueueSize;
        if(!otherQueue.isEmptyQueue()){
            int temp = otherQueue.queueFront;
            while (temp != otherQueue.queueRear) {
                addQueue(otherQueue.list[temp]);
                temp = (temp + 1) % otherQueue.maxQueueSize;
            }
            addQueue(otherQueue.list[temp]);
            temp = (temp + 1) % otherQueue.maxQueueSize;
            addQueue(otherQueue.list[temp]);

        }
    }






    QueueType(QueueType<Type>& otherQueue){ // To create a Queue object that copies another queue
        initializeQueue(otherQueue.maxQueueSize);

//        maxQueueSize = otherQueue.maxQueueSize;
        if(!otherQueue.isEmptyQueue()){
           int temp = otherQueue.queueFront;

           while (temp != otherQueue.queueRear) {
               addQueue(otherQueue.list[temp]);
               temp = (temp + 1) % otherQueue.maxQueueSize;

           }
            addQueue(otherQueue.list[temp]);
            temp = (temp + 1) % otherQueue.maxQueueSize;
//            addQueue(otherQueue.list[temp]);

        }else{
            throw  runtime_error("empty is in construstor");
        }

    };

    ~QueueType(){
        delete[]list;
    };

    void print(){
        Type temp = queueFront;
        while (temp!=queueRear){
            cout << list[temp] << ' ';
            temp = (temp+1) % maxQueueSize;
        }
        cout << list[temp] << ' ';

    }
private:
    int maxQueueSize;
    int count{};
    int queueFront{};
    int queueRear{};
    Type *list;
};








class Node {
public:
    int data;
    Node *next;

    Node() {
        this->next = NULL;
    }

    Node(int x) {
        this->data =x;
        this->next = NULL;
    }

    void print() {
        cout << data << " ";
    }
};




class MyQueueLinkedList {
    Node * head;
    Node * tail;
public:

    MyQueueLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int x) {
        Node * temp = new Node(x);
        if (head== nullptr){
            head = temp;
            tail = temp;
        }else {
            tail->next = temp;
            tail = temp;
        }
    }

    int pop() {
        int data;
        data = head->data;
        if (head->next== nullptr){
            head = nullptr;
            tail = nullptr;
            return data;
        }
        head = head->next;
        return data;

    }
    int peek() {
        return head->data;
    }

    bool empty() {
        return head== nullptr;
    }
};










int main() {





    QueueType<int> q;
    q.initializeQueue(100);
    q.addQueue(2);
    q.addQueue(2);
    q.addQueue(8);

    q.addQueue(3);
    q.addQueue(73);
    q.addQueue(73);
    q.deleteQueue();
    q.print();
    cout << endl;

    QueueType<int>q2(q);
//    cout << q2.isEmptyQueue();
//
    q2.print();
    q2.addQueue(2);
    q2.addQueue(2);
    q2.addQueue(8);
    q2.addQueue(3);
    cout << endl;
    q2.print();
//






    return 0;
}

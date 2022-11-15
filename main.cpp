#include <iostream>

using namespace std;


template<class Type>
class QueueType {
public:
    bool isEmptyQueue() {
        return count == 0;
    };

    bool isFullQueue() {
        return count == maxQueueSize;
    };

    void initializeQueue(int maxQueueSize) {
        queueFront = 1;
        queueRear = 0;
        count = 0;
        this->maxQueueSize = maxQueueSize;
        list = new Type[maxQueueSize];
    };

    Type front() {
        if (!isEmptyQueue()) {
            return list[queueFront];
        }
        throw runtime_error("is empty");


    };

    Type back() {
        if (!isFullQueue()) {
            return list[queueRear];
        }
        throw runtime_error("is full");

    };

    void addQueue(Type queueElement) {


        if (!isFullQueue()) {

            queueRear = (queueRear + 1) % maxQueueSize;
            count++;
            list[queueRear] = queueElement;
        } else throw runtime_error("queue is full");
    }

    void deleteQueue() {
        if (!isFullQueue()) {
            count--;
            queueFront = (queueFront + 1) % maxQueueSize;
        } else {
            cout << "Cannot remove from an empty queue" << '\n';
        }
    };

    explicit QueueType(int queueSize = 100) {
        if (queueSize <= 0) {
            cout << "Size can't be negative \n";
            throw (runtime_error("size is negative"));
        }
        list = new Type[queueSize];
        maxQueueSize = queueSize;

        queueFront = 1;
        queueRear = 0;

        count = 0;

    }; // Function with default parameters

    QueueType(const QueueType<Type> &otherQueue) {
        initializeQueue();
        maxQueueSize = otherQueue.maxQueueSize;
        if (!otherQueue.isEmptyQueue()) {
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


    QueueType(QueueType<Type> &otherQueue) { // To create a Queue object that copies another queue
        initializeQueue(otherQueue.maxQueueSize);

//        maxQueueSize = otherQueue.maxQueueSize;
        if (!otherQueue.isEmptyQueue()) {
            int temp = otherQueue.queueFront;

            while (temp != otherQueue.queueRear) {
                addQueue(otherQueue.list[temp]);
                temp = (temp + 1) % otherQueue.maxQueueSize;

            }
            addQueue(otherQueue.list[temp]);
            temp = (temp + 1) % otherQueue.maxQueueSize;
//            addQueue(otherQueue.list[temp]);

        } else {
            throw runtime_error("empty is in construstor");
        }

    };

    ~QueueType() {
        delete[]list;
    };

    void print() {
        Type temp = queueFront;
        while (temp != queueRear) {
            cout << list[temp] << ' ';
            temp = (temp + 1) % maxQueueSize;
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
        this->data = x;
        this->next = NULL;
    }

    void print() {
        cout << data << " ";
    }
};


class MyQueueLinkedList {
    Node *head;
    Node *tail;
public:

    MyQueueLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int x) {
        Node *temp = new Node(x);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    int pop() {
        int data;
        data = head->data;
        if (head->next == nullptr) {
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
        return head == nullptr;
    }
};

template<class type>
class OrderedLinkedList {
public:
    Node *head;
    Node *tail;
    int size;


    bool isEmpty() {
        return head == nullptr;
    }

    void removeFront() {
        if (isEmpty()) {
            throw runtime_error("empty");
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }


    void removeBack() {
        if (isEmpty()) {
            throw runtime_error("empty");
        }
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw runtime_error("index out of range");
        }
        if (index == 0) {
            removeFront();
            return;
        }
        if (index == size - 1) {
            removeBack();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        size--;
    }

    bool search(type item) {
        Node *current = head;
        bool found = false;
        bool stop = false;
        while (current != NULL && !found && !stop) {
            if (current->data == item) {
                found = true;
            } else {
                if (current->data > item) {
                    stop = true;
                } else {
                    current = current->next;
                }
            }
        }

        return found;
    }

    void add(type item) {
        if (head == NULL) {
            Node *newNode = new Node(item);
            head = newNode;
            size++;
        } else {
            Node *current = head;
            Node *previous = NULL;
            bool stop = false;
            while (current != NULL && !stop) {
                if (current->data > item) {
                    stop = true;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
            Node *temp = new Node(item);
            if (previous == NULL) {
                temp->next = head;
                head = temp;
                size++;
            } else {
                temp->next = current ;
                previous->next = temp;
                size++;
            }
        }
    }
   



};

template<typename type>

ostream& operator<< (ostream& os, const OrderedLinkedList<type>& ol) {
    //operator for printing the data of every Node in the list.
    Node *current = ol.head;
    while (current != NULL) {
        os<<current->data<<' ';
        current = current->next;
    }
    return os;
}






















    int main() {

OrderedLinkedList<int> arr;
arr.add(1);
arr.add(2);
arr.add(3);
arr.add(4);
arr.add(10);
arr.add(5);
arr.add(7);
arr.add(6);
cout << arr;








        QueueType<int> q;
        q.initializeQueue(100);
        q.addQueue(2);
        q.addQueue(2);
        q.addQueue(8);

        q.addQueue(3);
        q.addQueue(73);
        q.addQueue(73);
        q.deleteQueue();
//        q.print();
        cout << endl;

        QueueType<int> q2(q);
//    cout << q2.isEmptyQueue();
//
//        q2.print();
        q2.addQueue(2);
        q2.addQueue(2);
        q2.addQueue(8);
        q2.addQueue(3);
//        cout << endl;
//        q2.print();
//






        return 0;
    }

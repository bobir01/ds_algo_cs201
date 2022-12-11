#include <iostream>

using namespace std;


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


template<class type>
class LinkedList {
public:
    Node *head;
    Node *tail;
    int size;


    bool isEmpty() {
        return head == nullptr;
    }

    Node *get(int indx) {
        Node *temp = head;
        int count = 0;
        while (count == indx) {
            temp = temp->next;
            count++;
        }
        return temp;
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


    void clear_list() {
        Node *temp = head;
        Node *store;
        while (temp->next) {
            store = temp;
            delete temp;
            temp = store;
            temp= temp->next;
        }
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


    void insertLast(type item) {
        Node *temp = new Node(item);
        if (isEmpty()) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    /// insert at ordered position
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
                temp->next = current;
                previous->next = temp;
                size++;
            }
        }
    }


};

template<typename type>

ostream &operator<<(ostream &os, const LinkedList<type> &ol) {
    //operator for printing the data of every Node in the list.
    Node *current = ol.head;
    while (current != NULL) {
        os << current->data << ' ';
        current = current->next;
    }
    return os;
}


void swapNodes(Node *a, Node *b) {
//    int temp = a->data;
//    a->data = b->data;
//    b->data = temp;
    // x = x ^ y ^ (y = x);
    a->data = a->data ^ b->data ^ (b->data = a->data);
    // I learnt this trick from the internet, it's a very cool trick.
}

template<typename type>
void BubbleSort(LinkedList<type> &list) {
    Node *current = list.head;
    Node *next = list.head->next;

    while (current->next) {

        while (next) {
            if (current->data > next->data) {
                swapNodes(current, next);
                next = next->next;
                continue;
            }
            next = next->next;
        };

        current = current->next;
        next = current->next;

    }


}


template<typename type>
void InsertionSort(LinkedList<type> &list) {
    Node *sorted = NULL;
    Node *curr = list.head;
    while (curr) {
        if (sorted == NULL) {
            Node *temp1 = new Node(curr->data);
            temp1->next = sorted;
            sorted = temp1;
            curr = curr->next;
        } else {
            Node *current = sorted;
            Node *previous = NULL;
            bool stop = false;
            while (current != NULL && !stop) {
                if (current->data > curr->data) {
                    stop = true;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
            Node *temp = new Node(curr->data);
            if (previous == NULL) {
                temp->next = sorted;
                sorted = temp;

            } else {
                temp->next = current;
                previous->next = temp;
            }

        }
        curr = curr->next;
    }
    list.clear_list();
    list.head = sorted;

}


template<typename type>
void SelectionSort(LinkedList<type> & list){
    Node* curr = list.head;
    Node * next = list.head->next;
    Node* min_node;
    while (curr->next){
        min_node = curr;
        while (next){
            if(min_node->data>next->data){
                min_node = next;
                next = next->next;
            }
            next = next->next;

        }
    }

}

int main() {

    LinkedList<int> list;
    list.insertLast(5);
    list.insertLast(4);
    list.insertLast(3);
    list.insertLast(2);
    list.insertLast(1);
    list.insertLast(0);
    list.insertLast(6);
    list.insertLast(7);
    list.insertLast(8);
    list.insertLast(9);
    list.insertLast(10);
    list.insertLast(19);
    list.insertLast(18);
    list.insertLast(17);
    list.insertLast(16);
    list.insertLast(15);


    cout << list << endl;
//    BubbleSort(list);
    InsertionSort(list);
    cout << list << endl;


    return 0;
}

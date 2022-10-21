
#include <ostream>
#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    void print() {
        cout << data << " ";
    }
};

class LinkedList {
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtLast(int data) {
        Node *node = new Node(data);
        if (size == 0) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }


    void print() {
//        Node *temp = head;
//        while (temp != NULL) {
//            temp->print();
//            temp = temp->next;
//        }
//        cout << endl;
        printRec(head);
    }

    void removeFirst() {
        if (size == 0) {
            cout << "List is empty" << endl;
        } else if (size == 1) {
            head = NULL;
            tail = NULL;
            size = 0;
        } else {
            head = head->next;
            size--;
        }
    }

    int getFirst() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return -1;
        } else {
            return head->data;
        }
    }

    int getLast() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return -1;
        } else {
            return tail->data;
        }
    }

    int getAt(int idx) {
        if (size == 0) {
            cout << "List is empty" << endl;
            return -1;
        } else if (idx < 0 || idx >= size) {
            cout << "Invalid arguments" << endl;
            return -1;
        } else {
            Node *temp = head;
            for (int i = 0; i < idx; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void addFirst(int data) {
        Node *node = new Node(data);
        if (size == 0) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
        size++;
    }


    bool atIndex(int index, int data){
        if (index < 0 || size < index) return false;
        else if(size==0) addFirst(data);
        else {
            Node *temp = head;
            for (int i=0; i<=index; ++i) {
                temp = temp->next;
            }
            Node * new_= new Node(data);
            new_->next = temp->next;
            temp->next= new_;


            return true;
        }
    }



    void printRec(Node *curr) {
        if (curr) {
            Node * node = curr;
            node = curr->next;
            printRec(node);
            cout << curr->data << endl;
        }
    }

};



int main() {
    LinkedList obj;


    for (int i = 0; i < 10; i++) {
        obj.insertAtLast(i + 10);
    }
    obj.atIndex(4, 1000);
    cout << "Output is" << endl;
    obj.print();
    return 0;
}

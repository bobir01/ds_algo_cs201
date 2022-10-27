
#include <ostream>
#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node *next;

    Node() {
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


    void copyList(Node * listhead){
        while (listhead){
            this->insertAtLast(listhead->data);
            listhead = listhead->next;
            size++;
        }
        tail->next = listhead;
    }





    void insertAtLast(int data) {
        Node *node = new Node;
        node -> data = data;
        if (size == 0) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }


    void traverse() {
        Node *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
        cout << endl;
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
        Node *node = new Node;
        node ->data = data;
        if (size == 0) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
        size++;
    }


    bool atIndex(int index, int data) {
        if (index < 0 || size < index) return false;
        else if (size == 0) addFirst(data);
        else {
            Node *temp = head;
            for (int i = 0; i <= index; ++i) {
                temp = temp->next;
            }
            Node *new_ = new Node;
            new_ -> data = data;
            new_->next = temp->next;
            temp->next = new_;


            return true;
        }
        return false;
    }



    bool isInList(int data){
        Node * temp = head;
        while(temp){
            if (temp->data ==data) {
                return true;
            }
            temp = temp -> next;
        }
        return false;

    }



    void printRec(Node *curr) {
        if (curr) {
            Node *node = curr;
            node = curr->next;
            printRec(node);
            cout << curr->data << endl;
        }
    }



    LinkedList unionlist(Node *objhead){
        LinkedList temp;
        int c=0;
        while(objhead){
            cout <<  c << " ";
            if (isInList(objhead->data)){
                objhead = objhead->next;
                c++;
                continue;
            }
            temp.insertAtLast(objhead->data);
            objhead = objhead->next;
            c++;
        }
        return  temp;

    }






};


void merge_lists(LinkedList a , LinkedList b ){
    a.tail->next = b.head;
}




// task1 Middle of linked list

Node *middleNode(Node *head) {
    int size = 0;
    for (Node *temp = head; temp != nullptr; temp = temp->next, size++) {};
    int count = 0;
    Node *res;
    for (Node *temp = head; temp != nullptr; temp = temp->next, count++) {
        if (count == (size / 2)) {
            res = temp;
        }
    }
    return res;
}


int main() {
    LinkedList a;
    LinkedList b;


    for (int i = 0; i < 4; i++) {
        a.insertAtLast(i + 8);

    }

    for (int i = 0; i < 4; i++) {
        b.insertAtLast(i + 10);
    }

    LinkedList c = a.unionlist(b.head);
    c.traverse();

//    merge_lists(a, b);
//    a.copyList(b.head);
//    a.insertAtLast(10000);
//    a.traverse();

    return 0;
}

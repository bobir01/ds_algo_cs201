#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

template<class type>
class Stacks {
private:
    type *source;
    int stack_top{-1};
    int max_size{100};

public:
    explicit Stacks(int max_size = 100) {
        source = new type[max_size];
        stack_top = -1;
        max_size = max_size;
    }



    bool isFull() {
        return stack_top == max_size;
    }

    bool isEmpty() {
        return stack_top == -1;
    }


    void push(type newElement) {
        if (!isFull()) {
            if (isEmpty()) {
                stack_top++;
                source[stack_top] = newElement;
                stack_top++;
                return;
            }
            source[stack_top] = newElement;
            stack_top++;
        } else {
            throw runtime_error("Stack is full");
        }
    }

    type pop() {
        if (!isEmpty()) {
            stack_top--;
            return source[stack_top];
        }
        throw runtime_error("stack is empty");
    }

    type top_stack() {
        if (!isEmpty()) {
            return source[stack_top-1];

        }
        throw runtime_error("stack is empty");
    }


    int count() {
        return stack_top;
    }

    void print() {
        for (int i = 0; i < count(); ++i) {
            cout << source[i] << " ";
        }
        cout << endl;
    }

    void reverse() {
        int temp = stack_top;
        for (int i = 0; i < count(); ++i) {
            cout << source[temp] << ' ';
            temp--;
        }
        cout << "\n";

    }

    void reverse(bool string) {
        int temp = stack_top;
        for (int i = 0; i < count(); ++i) {
            cout << source[temp];
            temp--;
        }
        cout << "\n";

    }


    type sum() {
        int res = 0;
        for (int i = 0; i < count(); i++) {
            res += source[i];
        }
        return res;
    }
};


template<class type>
class Node {
public:
    type data;
    Node *next;

    Node() {
        this->next = NULL;
    }

    Node(type data) {
        this->data = data;
        this->next = NULL;
    }

    void print() {
        cout << data << " ";
    }
};


template<class type>
class LinkedList {
public:
    Node<type> *head;
    Node<type> *tail;
    int size;

    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtLast(int data) {
        auto *node = new Node<type>;
        node->data = data;
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
        Node<type> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
        cout << endl;
    }

    void print() {
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

    void removeLast() {
        if (size == 0) {
            cout << "List is empty" << endl;
        } else if (size == 1) {
            head = NULL;
            tail = NULL;
            size = 0;
        } else {
            Node<type> *temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            size--;
        }
    }

    type getFirst() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return -1;
        } else {
            return head->data;
        }
    }

    type getLast() {
        if (size == 0) {
            throw runtime_error("empty");
        }
        return tail->data;

    }

    type getAt(int idx) {
        if (size == 0) {
            throw runtime_error("empty");
        } else if (idx < 0 || idx >= size) {
            throw runtime_error("invalid index");
        } else {
            Node<type> *temp = head;
            for (int i = 0; i < idx; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void addFirst(int data) {
        auto *node = new Node<type>;
        node->data = data;
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
            auto *temp = head;
            for (int i = 0; i <= index; ++i) {
                temp = temp->next;
            }
            auto *new_ = new Node<type>;
            new_->data = data;
            new_->next = temp->next;
            temp->next = new_;


            return true;
        }
        return false;
    }

    bool isInList(int data) {
        auto *temp = head;
        while (temp) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;

    }

    void printRec(Node<type> *curr) {
        if (curr) {
            auto *node = curr;
            node = curr->next;
            printRec(node);
            cout << curr->data << endl;
        }
    }


    void remove_index(int indx) {
        if (indx < 0 || indx >= size) {
            throw runtime_error("invalid index");
        } else if (indx == 0) {
            removeFirst();
        } else if (indx == size - 1) {
            removeLast();
        } else {
            Node<type> *temp = head;
            for (int i = 0; i < indx - 1; i++) {
                temp = temp->next;
            }
            Node<type> *a = temp->next;
            temp->next = a->next;
            delete a;
            size--;
        }
    }

    void insertLast(type data) {
        auto *node = new Node<type>;
        node->data = data;
        if (size == 0) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }

};


template<class type>
class LinkedListStack {
private:
    LinkedList<type> *list;
    int size{0};
    int top;
public:
    LinkedListStack() {
        list = new LinkedList<type>;
        top = -1;
    }

    LinkedListStack(string s) {
        list = new LinkedList<type>;
        top = -1;
        for (char &i: s) {
            push(i);
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(type data) {
        if (isEmpty()) {
            list->addFirst(data);
            top++;
            size++;
            return;
        }

        list->insertAtLast(data);
        top++;
        size++;
    }


    type pop() {
        if (!isEmpty()) {
            type temp = list->getAt(top);
            list->removeLast();
            top--;
            size--;
            return temp;
        }
        throw runtime_error("stack is empty");
    }

    type getTop() {
        if (!isEmpty()) {
            return list->getAt(top);
        }
        throw runtime_error("stack is empty");
    }

    void print() {
        list->print();
    }

    int sizeOf() {
        return size;
    }


    bool isPalindrome() {
        for (int i = 0; i < sizeOf(); ++i) {
            if (list->getAt(i) != pop()) return false;
        }
        return true;

    }
};


double postfix_eval(string exp) {
    auto list = new Stacks<double>(exp.length());
    string temp = "";

    for (auto i: exp) {
        if (i == '-') {
            auto a = list->pop();
            auto b = list->pop();
            list->push(b - a);
            continue;
        } else if (i == '+') {
            auto a = list->pop();
            auto b = list->pop();
            list->push(a + b);
            continue;
        } else if (i == '*') {
            auto a = list->pop();
            auto b = list->pop();
            list->push(a * b);
            continue;

        } else if (i == '/') {
            auto a = list->pop();
            auto b = list->pop();
            list->push(b / a);
            continue;
        }
        temp.push_back(i);
        list->push(stod(temp));
//        list->print();
        temp.clear();

    }
    return list->pop();
}


int main() {
//    Stacks<int> list;
//    list.push(100);
//    list.push(200);
//    list.push(300);
//    list.push(400);
//    list.push(500);
//    list.push(600);
//    list.push(700);
//    list.push(800);
//    list.push(900);
//
//    cout << list.pop() << endl;
//    cout << list.pop() << endl;
//    cout << list.pop() << endl;
//    cout << list.pop() << endl;
//    cout << list.top_stack() << ' ';
//
//    list.print();
//    cout << list.count();
//    cout << list.sum() << " ";
//    cout << "reversed stack print\n";
//    list.reverse();
//    Stacks<char> userStack("Bobir");
//    userStack.reverse(true);


//    LinkedListStack<char> plind("ammm1ma");
//
//    plind.isPalindrome() ? (cout <<  "true" ) : (cout << "false");


//    cout << "Postfix: 82+3*64/-\nAnswer: " << postfix_eval("82+3*64/-") << endl;
    vector<string> operations = {"1", "C"};
//

    Stacks<int> stack;
    for (auto i: operations) {
        if (i == "+") {
            auto a = stack.pop();
            auto b = stack.pop();
            stack.push(b);
            stack.push(a);
            stack.push(a + b);
            stack.print();
            continue;
        } else if (i == "C") {
            stack.pop();
            stack.print();
            continue;
        } else if (i == "D") {
            stack.push(2 * stack.top_stack());
            stack.print();
            continue;
        }
        stack.push(stoi(i));
        stack.print();
    }
    cout <<stack.sum() << endl;


    return 0;

}

#include <iostream>

using namespace std;

template<class type>class Stacks{
private:
    type *source;
    int stack_top{-1};
    int max_size=100;

public:
    explicit Stacks(type max_size=100){
        source = new type[max_size];
        stack_top = -1;
    }

    Stacks(string name){
        source = new type[max_size];
        stack_top = -1;
        for (auto i: name) {
            push(i);
        }
    }


    bool isFull(){
        return stack_top == max_size;
    }

    bool isEmpty(){
        return stack_top ==-1;
    }


    void push(type newElement){
        if (!isFull()){
            if (isEmpty()){
                stack_top++;
                source[stack_top] = newElement;
                stack_top++;
                return;
            }
            source[stack_top] = newElement;
            stack_top++;
        } else{
            throw runtime_error("Stack is full");
        }
    }

    type pop(){
        if (!isEmpty()){
            stack_top--;
            return source[stack_top];

        }
        throw runtime_error("stack is empty");
    }

    type top_stack(){
        if (!isEmpty()){
            return source[stack_top];

        }
        throw runtime_error("stack is empty");
    }

    int count(){
        return stack_top+1;
    }

    void print(){
        for (int i = 0; i < count()-1; ++i) {
            cout << source[i] << " ";
        }
        cout << endl;
    }
    void reverse() {
        int temp = stack_top-1;
        for (int i = 0; i < count()-1; ++i) {
            cout << source[temp] << ' ';
            temp--;
        }
        cout << "\n";

    }
    void reverse(bool string){
        int temp = stack_top-1;
        for (int i = 0; i < count()-1; ++i) {
            cout << source[temp];
            temp--;
        }
        cout << "\n";

    }

};

int main() {
    Stacks<int> list;
    list.push(100);
    list.push(200);
    list.push(300);
    list.push(400);
    list.push(500);
    list.push(600);
    list.push(700);
    list.push(800);
    list.push(900);

//    cout << list.pop() << endl;
//    cout << list.pop() << endl;
//    cout << list.pop() << endl;
//    cout << list.pop() << endl;

    list.print();
    cout << "reversed stack print\n";
    list.reverse();
    Stacks<char> userStack("Bobir");
    userStack.reverse(true);



        return 0;

}

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



class Book{
    //create private members as String Name_book, Name_author, Name_publisher, AssignedCMS; int ISSN, Edition; bool isAvailable;
    string Name_book;
    string Name_author;
    string Name_publisher;
    string AssignedCMS;
    int ISSN;
    int Edition;
    bool isAvailable;
public:
    //getter and setter functions for all the private members
    string getName_book() const {
        return Name_book;
    }
    void setName_book(string Name_book) {
        Book::Name_book = Name_book;
    }
    string getName_author() const {
        return Name_author;
    }
    void setName_author(string Name_author) {
        Book::Name_author = Name_author;
    }
    string getName_publisher() const {
        return Name_publisher;
    }
    void setName_publisher(string Name_publisher) {
        Book::Name_publisher = Name_publisher;
    }
    string getAssignedCMS() const {
        return AssignedCMS;
    }
    void setAssignedCMS(string AssignedCMS) {
        Book::AssignedCMS = AssignedCMS;
    }
    int getISSN() const {
        return ISSN;
    }
    void setISSN(int inputISSN){
        Book::ISSN = inputISSN;
    }
    void setEdition(int EditionFun){
        this->Edition = EditionFun;
    }
    Book() {
        /*
         *Default constructor
         */
        ISSN = 0;
        Edition = 0;
        isAvailable = true;
    }
    Book(string Name_bookFun,string Name_authorFun,string Name_pubFun,int ISSNFun ){
        /*
         * Default constructor
         */
        this->Name_book = Name_bookFun;
        this->Name_author = Name_authorFun;
        this->Name_publisher = Name_pubFun;
        this->ISSN = ISSNFun;
        this->Edition = 0;
        this->isAvailable = true;
    }
    Book(string Name_bookFun,string Name_authorFun,string Name_pubFun,int ISSNFun , int EditionFun){
        /*
         * Default constructor
         */
        this->Name_book = Name_bookFun;
        this->Name_author = Name_authorFun;
        this->Name_publisher = Name_pubFun;
        this->ISSN = ISSNFun;
        this->Edition = EditionFun;
        this->isAvailable = true;
    }
    bool DispDetails(string Name_bookFun){
        if (this->Name_book == Name_bookFun){
        cout << "Book Name: " << this->Name_book << endl;
        cout << "Author Name: " << this->Name_author << endl;
        cout << "Publisher Name: " << this->Name_publisher << endl;
        cout << "ISSN: " << this->ISSN << endl;
        cout << "Edition: " << this->Edition << endl;
        cout << "isAvailable: " << this->isAvailable << endl;
    }else{
            return false;
        }

}
    bool DispDetails(int ISSNFun){
        if (this->ISSN == ISSNFun) {
            cout << "Book Name: " << this->Name_book << endl;
            cout << "Author Name: " << this->Name_author << endl;
            cout << "Publisher Name: " << this->Name_publisher << endl;
            cout << "ISSN: " << this->ISSN << endl;
            cout << "Edition: " << this->Edition << endl;
            cout << "isAvailable: " << this->isAvailable << endl;
        }else
            return false;
    }
    void DispDetails(){
        cout << "Book Name: " << this->Name_book << endl;
        cout << "Author Name: " << this->Name_author << endl;
        cout << "Publisher Name: " << this->Name_publisher << endl;
        cout << "ISSN: " << this->ISSN << endl;
        cout << "Edition: " << this->Edition << endl;
        cout << "isAvailable: " << this->isAvailable << endl;
    }

    bool AvailabilityStatus(){
        return this->isAvailable;
    }

    bool issueBook(string CMS){
        /*
         * This function will issue the book to the CMS and will change the isAvailable status to false
         * * --params:
         * string: CMS unique ID of the student
         * returns: bool true if the book is issued successfully otherwise false
         */
        if (this->isAvailable == true){
            this->isAvailable = false;
            this->AssignedCMS = CMS;
            return true;
        }else{
            return false;
        }
    }

};




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
        };

    }
    return 0;
}

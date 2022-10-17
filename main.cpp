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
        this->capacity = capacity;
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


class Book {
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
    string getName_book(string basicString) const {
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

    void setISSN(int inputISSN) {
        Book::ISSN = inputISSN;
    }

    void setEdition(int EditionFun) {
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

    Book(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSNFun) {
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

    Book(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSNFun, int EditionFun) {
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

    bool DispDetails(string Name_bookFun) {
        if (this->Name_book == Name_bookFun) {
            cout << "Book Name: " << this->Name_book << endl;
            cout << "Author Name: " << this->Name_author << endl;
            cout << "Publisher Name: " << this->Name_publisher << endl;
            cout << "ISSN: " << this->ISSN << endl;
            cout << "Edition: " << this->Edition << endl;
            cout << "isAvailable: " << this->isAvailable << endl;
        } else {
            return false;
        }

    }

    bool DispDetails(int ISSNFun) {
        if (this->ISSN == ISSNFun) {
            cout << "Book Name: " << this->Name_book << endl;
            cout << "Author Name: " << this->Name_author << endl;
            cout << "Publisher Name: " << this->Name_publisher << endl;
            cout << "ISSN: " << this->ISSN << endl;
            cout << "Edition: " << this->Edition << endl;
            cout << "isAvailable: " << this->isAvailable << endl;
        } else
            return false;
    }

    void DispDetails() {
        cout << "Book Name: " << this->Name_book << endl;
        cout << "Author Name: " << this->Name_author << endl;
        cout << "Publisher Name: " << this->Name_publisher << endl;
        cout << "ISSN: " << this->ISSN << endl;
        cout << "Edition: " << this->Edition << endl;
        cout << "isAvailable: " << this->isAvailable << endl;
    }

    bool AvailabilityStatus() {
        return this->isAvailable;
    }

    bool issueBook(string CMS) {
        /*
         * This function will issue the book to the CMS and will change the isAvailable status to false
         * * --params:
         * string: CMS unique ID of the student
         * returns: bool true if the book is issued successfully otherwise false
         */
        if (this->isAvailable == true) {
            this->isAvailable = false;
            this->AssignedCMS = CMS;
            return true;
        } else {
            return false;
        }
    }

};


class Librarian {
    //String Librarian; int maxBookNums, currBooksNum; Book *booksPtr;
    string librarian;
    int maxBookNums;
    int currBooksNum;
    Book *booksPtr;
public:
    //getter and setter functions for all the private members
    string getLibrarian() const {
        return librarian;
    }

    void setLibrarian(string Librarian) {
        Librarian::librarian = Librarian;
    }

    int getMaxBookNums() const {
        return maxBookNums;
    }

    void setMaxBookNums(int maxBookNums) {
        Librarian::maxBookNums = maxBookNums;
    }

    int getCurrBooksNum() const {
        return currBooksNum;
    }

    void setCurrBooksNum(int currBooksNum) {
        Librarian::currBooksNum = currBooksNum;
    }

    Book *getBooksPtr() const {
        return booksPtr;
    }

    void setBooksPtr(Book *booksPtr) {
        Librarian::booksPtr = booksPtr;
    }

    Librarian() {
        /*
         * Default constructor
         */
        this->librarian = " ";
        this->maxBookNums = 0;
        this->currBooksNum = 0;
        this->booksPtr = nullptr;
    }

    Librarian(string LibrarianFun, int maxBookNumsFun) {
        /*
         * Default constructor
         */
        this->librarian = LibrarianFun;
        this->maxBookNums = maxBookNumsFun;
        this->currBooksNum = 0;
        this->booksPtr = new Book[maxBookNumsFun];
    }

    void addBook(Book book) {
        /*
         * This function will add the book to the library
         * --params:
         * Book: book object
         * returns: void
         */
        if (this->currBooksNum < this->maxBookNums) {
            this->booksPtr[this->currBooksNum] = book;
            this->currBooksNum++;
        } else {
            cout << "Library is full" << endl;
        }
    }

    void addBook(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSNFun) {
        /*
         * This function will add the book to the library
         * --params:
         * Book: book object
         * returns: void
         */
        if (this->currBooksNum < this->maxBookNums) {
            Book book(Name_bookFun, Name_authorFun, Name_pubFun, ISSNFun);
            this->booksPtr[this->currBooksNum] = book;
            this->currBooksNum++;
        } else {
            cout << "Library is full" << endl;
        }
    }

    void searchBook(string Name_bookFun) {
        /*
         * This function will search the book in the library
         * --params:
         * string: Name_bookFun
         * returns: void
         */
        for (int i = 0; i < this->currBooksNum; ++i) {
            if (this->booksPtr[i].getName_book(Name_bookFun) == Name_bookFun) {
                if (this->booksPtr[i].AvailabilityStatus() == true) {
                    cout << "Book is available" << endl;

//                    this->booksPtr[i].DispDetails(Name_bookFun);
                    cout << "Book is available" << "at index " << i << endl;
                    break;
                }
            }
        }
        cout << "Book is not available" << endl;

    }

    void issueBook(string Name_bookFun, string CMS) {
        /*
         * This function will issue the book to the CMS
         * --params:
         * string: Name_bookFun
         * string: CMS unique ID of the student
         * returns: void
         */
        for (int i = 0; i < this->currBooksNum; ++i) {
            if (this->booksPtr[i].getName_book(Name_bookFun) == Name_bookFun) {
                if (this->booksPtr[i].issueBook(CMS) == true) {
                    cout << "Book is issued" << endl;
                    break;
                }
            }
        }
        cout << "Book is not issued due to some unavailablity or issued already " << endl;
    }
};


//task 3
class TwoDArray {
    int **arr;
    int row;
    int *col;
public:
    TwoDArray() {};

    TwoDArray(int row, int column[]) {
        this->row = row;
        this->col = column;
        this->arr = new int *[row];
        for (int i = 0; i < row; ++i) {
            this->arr[i] = new int[column[i]];
            this->col[i] = column[i];
        }
    }

    void setVal(int row, int column, int val) {
        this->arr[row][column] = val;
    }

    void print() {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->col[i]; ++j) {
                cout << this->arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};





int main() {
//    int capacity_user{0};
//    cout <<  "Enter capacity of array: " ;
//    cin >> capacity_user;
//    DynamicArray arr(capacity_user);
//    cout <<  "Size of array: "  << arr.getSize() << endl;
//    cout <<  "Capacity of array: "  << arr.getCapacity() << endl;
//    for (int i = 0; i < 100; ++i) {
//        cout << "Enter element: " ;
//        cin >> capacity_user;
//        arr.add(capacity_user);
//        if (capacity_user==100) {
//            break;
//        };
//
//    }


    int col[3] = {3, 2, 4,};


    TwoDArray arr2(3, col);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < col[i]; ++j) {
            arr2.setVal(i, j, 0);
        }
    }
    arr2.print();


    return 0;
}

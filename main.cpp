#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
//task1
/*
struct empInfo{
    int id=0;
    string designation;
    void input(){
        cout << "Enter the id: \n" ;
        cin >> id;
        cout << "Enter the designation: \n";
        cin >> designation;
    };
    void display(){
        cout << "Id: " + to_string(id) + "\n" +
                "Designation: " + designation<< "\n";
    };
};
*/


// task2
/*
class empInfoClass{
private:
    string name, email, designation;
    int id{0};
public:
    empInfoClass(int userId, string userName, string userEmail, string userDesignation){
        name = userName;
        email = userEmail;
        designation = userDesignation;
        id = userId;
    };
    void display(){
        cout << "Id: " + to_string(this->id) + "\n" +
                "Designation: " + this->designation<< "\n";
    };
    void input(){
        cout << "Enter the id: \n" ;
        cin >> id;
        cout << "Enter the name: \n";
        cin>>  name;
        cout << "Enter the email:\n";
        cin >> email;
        cout << "Enter the designation: \n";
        cin >> designation;
    };
    //setters \/
    void set_name(string userName) {
        this->name = userName;
    }
    void set_email(string userEmail) {
        this->email = userEmail;
    }
    void set_designation(string userDesignation){
        this->designation = userDesignation;
    }
    void set_id(int userId){
        this->id = userId;
    }
   //getters \/
    string get_name(){
        return name;
    }
    string get_email(){
        return  email;
    }
    string get_designation(){
        return designation;
    }
    int get_id(){
        return id;
    }

};


*/
//task3
class Book{
private:
    string Name_book, Name_author, Name_publisher, AssignedCMS;
    int ISSBN, Edition;
    bool isAvaible;
public:
    Book(){isAvaible= true;}         //i task
    Book(string Name_bookFun, string Name_authorFun,  string Name_pubFun, int ISSBNFun) { // ii
        this->Name_book= Name_bookFun;
        this->Name_author= Name_authorFun;
        this->Name_publisher = Name_pubFun;
        this->ISSBN = ISSBNFun;
    };
    Book(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSBNFun, int EditionFun)  {//iii
        this->Name_book= Name_bookFun;
        this->Name_author= Name_authorFun;
        this->Name_publisher = Name_pubFun;
        this->ISSBN = ISSBNFun;
        this->Edition = EditionFun;
        this->isAvaible = true;
    }
    void inputDetails(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSBNFun, int EditionFun){ //iv
        this->Name_book= Name_bookFun;
        this->Name_author= Name_authorFun;
        this->Name_publisher = Name_pubFun;
        this->ISSBN = ISSBNFun;
        this->Edition = EditionFun;
    }
    string getCSMid(){
        return AssignedCMS;
    }
    string getBookName(){
        return Name_book;
    }
    bool DispDetails(string Name_bookFun){ //V
        if(Name_bookFun== this->Name_book){
            cout << "Details:"<< "\n"<<
             "Author: " << this->Name_author << "\n"<<
             "Publisher: " << this->Name_publisher << "\n" <<
             "ISSBN: " << this->ISSBN << "\n"<<
             "Edition: "<< this->Edition << "\n";
            return true;
        };
            cout << "Sorry book is not found";
            return false;
        }

    bool DispDetails(int ISSBNFun){ // vi
        if(ISSBNFun == this->ISSBN){
            cout <<  "Book with ISSBN " << this->ISSBN << " is available" << "/n " <<
                 "Details:"<< "\n"<<
                 "Author: " << this->Name_author << "\n"<<
                 "Publisher: " << this->Name_publisher << "\n" <<
                 "Book name : " << Name_book  <<
                 "Edition: "<< this->Edition << "\n";
            return true;
        };
        cout << "Sorry book is not found";
        return false;
    };

    void DispDetails(){ //vii
        if(Name_book.length() > 0) {
            cout <<
                 "Book name : " << this->Name_book << "\n" <<
                 "Author: " << this->Name_author << "\n" <<
                 "Publisher: " << this->Name_publisher << "\n" <<
                 "ISSBN: " << ISSBN << "\n" <<
                 "Edition: " << this->Edition << "\n"
                 << "IsAvailable: " << isAvaible << " (1->true / 0->false)\n";
        }
    }

    bool AvailabilityStatus(){ //viii
        return isAvaible;
    }

    string issueBook(string userCMSiD){ // ix
        if (AssignedCMS.size()==0){
            this->AssignedCMS = userCMSiD;
            this->isAvaible = 0;
            return userCMSiD;
        };
        return "Sorry book was assigned to "+ AssignedCMS+"\n";

    }
};


class Library{
private:
    string Librarian;
    int maxBookNums, currBooksNum;
    Book booksCollection[100];
public:
    Library(string LibrarianFun){ //i
        this->Librarian = LibrarianFun;
        this->maxBookNums = 100;
        this->currBooksNum = 0;
    }

    void DispBookDetails(){ //ii
        for (int i = 0; i <sizeof(booksCollection)/sizeof(booksCollection[0]); ++i) {
            booksCollection[i].DispDetails();
        }
    }
    void addBook(string Name_bookFun, string Name_authorFun, string Name_pubFun, int ISSBNFun, int EditionFun){ //iii
        if(currBooksNum<100){
            booksCollection[currBooksNum] = Book(Name_bookFun, Name_authorFun, Name_pubFun, ISSBNFun, EditionFun);
            currBooksNum++;
//            cout << "Book was successfully added at i =" << currBooksNum << "\n" ;
//            booksCollection[currBooksNum-1].DispDetails();
        } else{
            cout << "Library is full!\n[ERROR] MaxNumberOfBooksExceededError\n";
        }
    }
    bool searchBook(string Name_bookFun){
        for (int i = 0; i < maxBookNums; i++) {
            if (booksCollection[i].getBookName()==Name_bookFun){
                if (booksCollection[i].AvailabilityStatus() ){
                    cout << "Book: " << Name_bookFun << " found, at index: " << i << "\n";
                    booksCollection[i].DispDetails();
                    currBooksNum= i;
                    return true;
                } else{
                    cout << "Not available!!! ;(\n"+Name_bookFun+" was assigned to " + booksCollection[i].getCSMid() << '\n';
                    return false;
                }
                };
            }
//            cout<< "Book is not available";
        return false;
    }
    void issueBook(string Name_bookFun, string AssignedCMSidFun){
        if (searchBook(Name_bookFun)){
            string assignedUser = booksCollection[currBooksNum].issueBook(AssignedCMSidFun);
            if (assignedUser.size()>40){
                cout <<assignedUser;
            }else{
                cout << Name_bookFun << " was successfully assigned to " + assignedUser<< "\n";
            }
        } else{
            cout << "Sorry, "+ Name_bookFun + " not found :(" << "\n";
        }
    }
};






int main() {
//    empInfo a;
//    a.display();
    Library lib = Library("BobdevLib");

    lib.addBook("Cp", "Saydullo", "SayMacLLc", 1234, 10);
    lib.addBook("Math", "Bobir", "bobdevLLC", 90002, 9);
    lib.addBook("Math2", "Bobir", "bobdevLLC", 90002, 9);
//    lib.searchBook("Math2");
    lib.issueBook("Cp","210030");
    lib.issueBook("math", "210030");
    lib.searchBook("Cp");
    lib.DispBookDetails();

    return 0;
}

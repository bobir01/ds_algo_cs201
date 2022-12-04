#include <iostream>
#include <string>
#include "WifeNode.h"
#include "ChildNode.h"
#include "HusbandNode.h"


using namespace std;

static int counter = 1;

class familyTree {
public:
    HusbandNode *HusbandHead = NULL;
    WifeNode *WifeHead = NULL;
    ChildNode *ChildHead = NULL;

    familyTree() {
        HusbandHead = NULL;
        WifeHead = NULL;
        ChildHead = NULL;
    }

    void addHusband(int age, string name) {
        HusbandNode *newHusband = new HusbandNode(age, name);
        newHusband->isMarried = true;
        if (HusbandHead == NULL) { // if the list of husbands is empty
            HusbandHead = newHusband;
        } else {
            HusbandNode *temp = HusbandHead;
            while (temp->next != NULL) { // go to the end of the list
                temp = temp->next;
            }
            temp->next = newHusband;
        }
    }

    void addWife(int age, string name) {
        WifeNode *newWife = new WifeNode(age, name);
        if (WifeHead == NULL) { // if the list of wives is empty
            WifeHead = newWife;
            HusbandNode *temp = HusbandHead;
            while (temp->next != NULL) { // go to the end of the list
                temp = temp->next;
            }
            temp->down = newWife;  // link the last husband to the new wife
            newWife->up = temp;   // link the new wife to the last husband
        } else {
            WifeNode *temp = WifeHead;
            while (temp->next != NULL) { // go to the end of the list
                temp = temp->next;
            }
            temp->next = newWife;
            HusbandNode *temp2 = HusbandHead;

            while (temp2->next != NULL) { // go to the end of the list
                temp2 = temp2->next;
            }
            temp2->down = newWife;  // link the last husband to the new wife
            newWife->up = temp2;   // link the new wife to the last husband

        }
    }

    void addChild(int age, string name) {
        ChildNode *newChild = new ChildNode(age, name);
        if (ChildHead == NULL) { // if the list of children is empty
            ChildHead = newChild;
            WifeNode *temp = WifeHead;
            while (temp->next != NULL) { // go to the end of the list
                temp = temp->next;
            }
            temp->down = newChild;  // link the last wife to the new child
            newChild->up = temp;   // link the new child to the last wife
        } else {
            ChildNode *temp = ChildHead;
            while (temp->next != NULL) { // go to the end of the list
                temp = temp->next;
            }
            temp->next = newChild;
            WifeNode *temp2 = WifeHead;
            while (temp2->next != NULL) { // go to the end of the list
                temp2 = temp2->next;
            }
            temp2->down = newChild;  // link the last wife to the new child
            newChild->up = temp2;   // link the new child to the last wife
        }
    }


    void printHusband() {
        HusbandNode *temp = HusbandHead;
        int i = 1;
        while (temp != NULL) {
            cout << i << ". " << temp->name << " " << temp->age << endl;
            temp = temp->next;
        }
    }

    void printWife() {
        WifeNode *temp = WifeHead;
        int i = 1;
        while (temp != NULL) {
            cout << i << ". " << temp->name << " " << temp->age << endl;
            temp = temp->next;
        }
    }

    void printChild() {
        ChildNode *temp = ChildHead;
        int i = 1;
        while (temp != NULL) {
            cout << i << ". " << temp->name << " " << temp->age << endl;
            temp = temp->next;
        }
    }


    void printFamily() {
        HusbandNode *husbandtemp = HusbandHead;
        WifeNode *wifetemp = WifeHead;
        ChildNode *childtemp = ChildHead;
        counter = 1;
        while (husbandtemp != NULL) {
            cout << counter << ". " << husbandtemp->name << " " << husbandtemp->age << ">>>";
            if (husbandtemp->down != NULL) {
                cout << husbandtemp->down->name << " " << husbandtemp->down->age << ">>>";
                if (husbandtemp->down->down != NULL) {
                    cout << husbandtemp->down->down->name << " " << husbandtemp->down->down->age << endl;
                } else {
                    cout << endl;
                }
            } else {
                cout << endl;
            }
            husbandtemp = husbandtemp->next;
            counter++;
            cout << endl;
        }
    }
    void manageFamily() {
        int choice = 0;

        while (choice != 4) {
            cout << "1. Add a husband" << endl;
            cout << "2. Add a wife" << endl;
            cout << "3. Add a child" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            if (choice == 1) {
                int age;
                string name;


                cout << "Enter the name of the husband: ";
                cin >> name;
                cout << "Enter the age of the husband: ";
                cin >> age;


                addHusband(age, name);
            } else if (choice == 2) {
                int age;
                string name;
                cout << "Enter the name of the wife: ";
                cin >> name;
                cout << "Enter the age of the wife: ";
                cin >> age;
                addWife(age, name);
            } else if (choice == 3) {
                int age;
                string name;
                cout << "Enter the name of the child: ";
                cin >> name;
                cout << "Enter the age of the child: ";
                cin >> age;
                addChild(age, name);
            } else if (choice == 4) {
                cout << "Exiting..." << endl;
            } else {
                cout << "Invalid input. Try again." << endl;
            }
        }
    }

    void findFamilyViaChildName(string name) {
        ChildNode *temp = ChildHead;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << temp->up->up->name << " " << temp->up->up->age << ">>>";
                cout << temp->up->name << " " << temp->up->age << ">>>";
                cout << temp->name << " " << temp->age << endl;
            }
            temp = temp->next;
        }
    }

    void findFamilyViaWifeName(string name) {
        WifeNode *temp = WifeHead;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << temp->up->name << " " << temp->up->age << ">>>";
                cout << temp->name << " " << temp->age << ">>>";
                if (temp->down != NULL) {
                    cout << temp->down->name << " " << temp->down->age << endl;
                } else {
                    cout << endl;
                }
            }
            temp = temp->next;
        }
    }

    void findFamilyViaHusbandName(string name) {
        HusbandNode *temp = HusbandHead;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << temp->name << " " << temp->age << ">>>";
                if (temp->down != NULL) {
                    cout << temp->down->name << " " << temp->down->age << ">>>";
                    if (temp->down->down != NULL) {
                        cout << temp->down->down->name << " " << temp->down->down->age << endl;
                    } else {
                        cout << endl;
                    }
                } else {
                    cout << endl;
                }
            }
            temp = temp->next;
        }
    }


};

int main() {
    familyTree family;
    family.manageFamily();
    family.printFamily();


    family.findFamilyViaChildName("adam1");


    return 0;
}

/*

1
bob1
20
2
jane1
20
3
adam1
1
bob2
20
2
jane2
20
1
bob3
20
4

*/

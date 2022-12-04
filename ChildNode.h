//
// Created by BOBIRJON MARDONOV on 04/12/22.
//

#ifndef DSALGOLAB4_CHILDNODE_H
#define DSALGOLAB4_CHILDNODE_H
#include <iostream>
#include <string>
#include "HusbandNode.h"
#include "WifeNode.h"


using namespace std;

class WifeNode;

class ChildNode {
public:
    int age{0};
    string name;
    ChildNode *next = NULL;
    WifeNode *up = NULL;
    ChildNode() {
        age = 0;
        name = "";
    }
    ChildNode(int age, string name) {
        this->age = age;
        this->name = name;
    }
};


#endif //DSALGOLAB4_CHILDNODE_H

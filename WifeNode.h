//
// Created by BOBIRJON MARDONOV on 04/12/22.
//

#ifndef DSALGOLAB4_WIFENODE_H
#define DSALGOLAB4_WIFENODE_H
#include <iostream>
#include <string>
#include "HusbandNode.h"
#include "ChildNode.h"
using namespace std;

class WifeNode {
public:
    int age{0};
    string name;
    WifeNode *next = NULL;
    HusbandNode *up = NULL;
    ChildNode *down = NULL;
    WifeNode() {
        age = 0;
        name = "";
    }
    WifeNode(int age, string name) {
        this->age = age;
        this->name = name;
    }
};

#endif //DSALGOLAB4_WIFENODE_H

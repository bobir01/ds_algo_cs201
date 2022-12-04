//
// Created by BOBIRJON MARDONOV on 04/12/22.
//

#ifndef DSALGOLAB4_HUSBANDNODE_H
#define DSALGOLAB4_HUSBANDNODE_H
#include <iostream>
#include <string>
#include "WifeNode.h"
#include "ChildNode.h"


using namespace std;


class HusbandNode {
public:
    int age{0};
    string name;
    bool isMarried{false};
    HusbandNode *next = NULL;
    WifeNode *down = NULL;
    HusbandNode() {
        age = 0;
        name = "";
    }
    HusbandNode(int age, string name) {
        this->age = age;
        this->name = name;
    }

};


#endif //DSALGOLAB4_HUSBANDNODE_H

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree{
public:
    TreeNode* root;
    Tree(){
        root = NULL;
    }
    void insert(int val){
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL){
            root = newNode;
            return;
        }
        TreeNode* temp = root;
        while(temp != NULL){
            if(val < temp->val){
                if(temp->left == NULL){
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }
    void print(TreeNode* root){
        if(root == NULL){
            return;
        }
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }
};










int main() {
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.print(tree.root);



    return 0;
}
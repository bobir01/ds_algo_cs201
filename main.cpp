#include <iostream>

using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int data, Node *nodePtr) {
        next = nodePtr;  // set next to point to the node pointed to by nodePtr as making it head node
        nodePtr = this;    // set nodePtr to point to this node which has been currently created
        this->data = data;   // updating node's values
    }
};

// apparently by this way you are pretending that your insert to the next node but at the same time you are changing the head node which is equal to making it kind of previous node
class List {
    Node *head;
public:
    List() {
        head = NULL;
    }

    void insertAtFront(int data) {
        Node *newNode = new Node(data, head);
    }

    void printAll() {
        Node *curr = head;
        while (curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
    }
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree {
public:
    TreeNode *root;

    Tree() {
        root = NULL;
    }

    void insert_(int val) {
        TreeNode *newNode = new TreeNode(val);
        if (root == NULL) {
            root = newNode;
            return;
        }
        TreeNode *temp = root;
        while (temp != NULL) {
            if (val == temp->val){throw runtime_error("Duplicate value!!!!! \n TreeNode-> val = " + to_string(temp->val));}
            if (val < temp->val) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    void insert(int insertItem)
    {
        TreeNode* current; //pointer to traverse the tree
        TreeNode* trailCurrent=NULL; //pointer behind current
        TreeNode* newNode; //pointer to create the node
        newNode = new TreeNode(insertItem);
        if (root == NULL)
            root = newNode;
        else
        {
            current = root;
            while (current != NULL)
            {
                trailCurrent = current;
                if (current->val == insertItem)
                {
                    cout << "The insert item is already in the list-\n";
                    cout << "duplicates are not allowed. " << insertItem << endl;
                    return;
                }
                else if (current->val > insertItem)
                    current = current->left;
                else
                    current = current->right;
            }//end while
            if (trailCurrent->val > insertItem)
                trailCurrent->left = newNode;
            else
                trailCurrent->right = newNode;
        }
    }




    void print(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }

    int height(TreeNode *p)  {
        if (p == nullptr) return 0;

        return 1 + max(height(p->left), height(p->right));
    }
    void inorder(TreeNode *ptr)
    {
        if(ptr)
        {
            inorder(ptr->left);
            cout<<ptr->val<<" ";
            inorder(ptr->right);
        }
    }

    TreeNode * search(int key)
    {
        TreeNode *t = root;
        while (t != NULL && t->val != key)
        {
            if (key < t->val)
                t = t->left;
            else
                t = t->right;
        }
        return t;
    }





    void destroy(TreeNode* &p)
    {
        if (p != NULL)
        {
            destroy(p->left);
            destroy(p->right);
            cout << "Deleting the node containing item " << p->val << endl;
            delete p;
            p = NULL;
        }
    }

    ~Tree()
    {
        destroy(root);
    }


};




void copyTree(TreeNode* & copiedTreeRoot,TreeNode* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new TreeNode(otherTreeRoot->val);
        copiedTreeRoot->val = otherTreeRoot->val;
        copyTree(copiedTreeRoot->left, otherTreeRoot->left);
        copyTree(copiedTreeRoot->right, otherTreeRoot->right);
    }
}











int main() {
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(6+10);
    tree.insert(6+20);
    tree.insert(692);
    tree.insert(69);
    tree.insert(91  );
    tree.print(tree.root);


//    cout << endl;
//    List obj;
//    obj.insertAtFront(10);
//    obj.insertAtFront(8);
//    obj.insertAtFront(6);
//    obj.insertAtFront(4);
//    obj.insertAtFront(2);
//    obj.insertAtFront(0);
//    obj.printAll();
    cout << "\n";
    cout << tree.height(tree.root);



    Tree obj;
    obj.insert(20);
    obj.insert(10);
    obj.insert(3);
    obj.insert(13);
    obj.insert(40);
    obj.insert(23);
    obj.insert(53);

    obj.insert(31);
    obj.insert(47);
    obj.insert(63);
    obj.insert(70);
    obj.insert(80);
    obj.insert(90);



    Tree obj2;
    obj2.insert(20);
    obj2.insert(10);
    obj2.insert(3);
    obj2.insert(13);
    obj2.insert(40);
    obj2.insert(23);
    obj2.insert(53);

    obj2.insert(31);
    obj2.insert(47);





    obj.print(obj.root);

    cout << "\n";

    cout << obj.height(obj.root);

    cout << "\n";
//    cout << obj.search(0)->val;

    cout << "\n\n";
    Tree obj3;
    obj3.insert(20);
    obj3.insert(10);
    obj3.insert(3);
    obj3.insert(11);
    copyTree(obj3.root,obj.root);

    cout
    << "\n\n";
    cout << obj3.height(obj3.root);
    obj3.print(obj3.root);

    cout << "\n\n";

    obj3.destroy(obj3.root);


    return 0;
}
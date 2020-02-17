#include <iostream>

struct Node{
public:
    Node* left = nullptr;
    Node* right = nullptr;
    int key;

    explicit Node(int elem): key(elem) {};
    Node(int elem, Node* left,  Node* right){
        this->left = left;
        this->right = right;
        key = elem;
    };
};

class Tree{
public:
    Node *root;

    Tree(Node* newRoot){
        root = newRoot;
    }

    void add(int elem){
        Node* currentNode = root;
        bool flag = true;
      while(flag){
            if (currentNode->key >= elem){
                if (currentNode->left) currentNode = currentNode->left;
                else {
                    currentNode->left = new Node(elem);
                    flag = false;
                }
            }
            else {
                if (currentNode->right) currentNode = currentNode->right;
                else {
                    currentNode->right = new Node(elem);
                    flag = false;
                }
            }
            }
        }

    void printInward(Node* root){
        if (root->left) printInward(root->left);
        std::cout <<  root->key << std::endl;
        if (root->right) printInward(root->right);
    }
};



int main() {
    Tree tree(new Node(5));
    tree.add(2);
    tree.add(6);
    tree.add(10);
    tree.add(1);
    tree.add(3);
    tree.add(4);

    tree.printInward(tree.root);
    return 0;
}

#include <iostream>

class Node{
public:
    Node(int i_key): key(i_key) {}
    int getKey() const{
        return key;
    }

    void add(int elem){

       if (elem <= key){
            if (left != nullptr){
                left->add(elem);
            }
            else{
                left = new Node(elem);
            }
        }
        else{
            if (right != nullptr){
                right->add(elem);
            }
            else{
                right = new Node(elem);
            }
        }

    }

    void printInward(){
        if (left) left->printInward();
        std::cout << key << " ";
        if (right) right->printInward();
    }

private:
    int key;
    Node *left = nullptr,
        *right = nullptr;

};

int main() {
    Node root(5);

    size_t n;
    while ((std::cin >> n) && (n != 0)){
        root.add(n);
    }

    root.printInward();
    std::cout << std::endl;
    return 0;
}

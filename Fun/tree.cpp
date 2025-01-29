/*********************************/
/*** Just a simple binary tree ***/
/*********************************/
#include <iostream>

using namespace std;

struct Node{
    int item;
    Node* right;
    Node* left;

    Node(int value){
        item = value;
        right = nullptr;
        left = nullptr;
    }
};

class Tree{
private:
    Node* head;
public:
    Tree(){
        head = nullptr;
    }

    void append(int value){
        Node* newItem = new Node(value);

        if(head == nullptr){
            head = newItem;
            return;             //return, because it's the first item.
        }

        Node* current = head;
        Node* last;
        while(true){
            if(current == nullptr){
                if(value > last->item)
                    last->right = newItem;
                else 
                    last->left = newItem;
                break;
            }
            
            last = current;
            if(newItem->item < current->item){
                current = current->left;
            } else if(newItem->item > current->item){
                current = current->right;
            } else {
                return;
            }
        }
    }

    void printTree(){
        //TODO: make this function
    }

    ~Tree(){}; //TODO: delete dynamically allocated memory later
};

int main(){
    Tree tree;

    tree.append(5);
    tree.append(3);
    tree.append(10);

    return 0;
}
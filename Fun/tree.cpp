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
            return;
        }

        if(value < head->item){
            //TODO: recursive calls to 
        }
    }

    ~Tree();
};

int main(){

}
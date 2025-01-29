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

    Node* get(){
        Node* h = head;
        return h;
    }

    //appending without recursive calls
    void append(int value){
        Node* newItem = new Node(value);

        if(head == nullptr){
            head = newItem;
            return;             //return, because it's the first item.
        }

        Node* current = head;
        Node* last;
        while(true){
            //if the last item was greater, it appends to the right, otherwise to the left
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
                delete newItem;
                return;
            }
        }
    }

    //Recursive printing (inorder)
    void printTree(Node* current) {
        if (current == nullptr) return;
        printTree(current->left);
        cout << current->item << " ";
        printTree(current->right);
    }

    //Deallocating the tree step by step (postorder)
    void deleteTree(Node* current){
        if (current == nullptr) return;
        deleteTree(current->left);
        deleteTree(current->right);

        cout << "deleting " << current->item << endl;
        delete current;
    }

    ~Tree(){
        deleteTree(head);
    };
};

int main(){
    Tree tree;

    //Testing append
    tree.append(5);
    tree.append(3);
    tree.append(10);

    //Testing printTree
    tree.printTree(tree.get());

    return 0;
}
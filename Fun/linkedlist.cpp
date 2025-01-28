/**************************************************/
/*** Just a simple linked list, because why not ***/
/**************************************************/

//(I should probably just go to sleep now)//

#include <iostream>

using namespace std;

//Node's struct with an integer, a pointer to the next node and a constructor.
struct Node{
    int item;
    Node* next;

    Node(int value){
        item = value;
        next = nullptr;
    }
};

//The linked list itself. Creates nodes and links them together, then deletes it with destructor.
class linkedlist{
private:
    Node* head;
public:
    linkedlist(){
        head = nullptr;
    };

    ~linkedlist() {
        for (Node* current = head; current != nullptr;) {
            Node* temp = current;
            current = current->next;
            delete temp;
    };
};

    void append(int value){
        Node* newItem = new Node(value);

        if(head == nullptr){
            head = newItem;
            return;             //returning because it's the first node.
        }

        for(Node* current = head; current != nullptr; current = current->next){
            if(current->next == nullptr){
                current->next = newItem;
                break;
            }
        }

    }

    void printList(){
        for(Node* current = head; current != nullptr; current = current->next){
            cout << current->item << endl;
        }
    }
};

int main(){
    linkedlist list;

    //trying the append function
    list.append(10);
    list.append(16);

    //...aand printing out the list
    list.printList();

    return 0;
}
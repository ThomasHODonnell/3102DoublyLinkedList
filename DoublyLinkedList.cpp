#include <iostream> 
#include <list>

using namespace std; 

class Node {
    public: 
        int key; 
        Node* next;
        Node* prev; 

        Node (int key) {
            this->key = key; 
            this->next = this->prev = nullptr; 
        }
}; 

class LinkedList {
    public: 
        int count; 
        Node* head;
        Node* tail; 

        LinkedList () {
            count = 0; 
            head = tail = nullptr; 
        }

        void insertF (int key) {
            Node* newNode = new Node(key); 
            if (count == 0) {
                head = tail = newNode; 
                newNode -> next = nullptr; 
                newNode -> prev = nullptr; 
            }
            else {
                 newNode -> next = head;
                 head -> prev = newNode;  
                 head = newNode;
                 newNode -> prev = nullptr; 
            }
            count++;
            return;
        }

        void insertL (int key) {
            Node* newNode = new Node(key); 
            if (head = nullptr) head = tail = newNode; 
            else {
                Node* current = head; 
                while (current -> next != nullptr) current = current -> next; 
                current -> next = newNode; 
                newNode -> prev = current; 
                newNode = tail; 
                newNode -> next = nullptr; 
            }
            count++; 
            return; 
        }

        int deleteF () {
            if (count == 0) return -1;  
            Node* temp = head; 
            int i = temp -> key; 
            head = head -> next; 
            delete temp; 
            head -> prev = nullptr; 
            if (head = nullptr) tail = nullptr; 
            count--; 
            return i; 
        }

        int deleteL () {
            Node* temp = head; 
            int i; 
            if (count == 0) return -1; 
            else {
                while (temp -> next != nullptr) temp = temp -> next; 
                i = temp -> key; 
                Node* newLast = temp -> prev; 
                newLast -> next = nullptr; 
                newLast = tail; 
                delete temp; 
            }
            count--; 
            return i;
        }

        void printAll () {
            Node* current = head;
            while (current != nullptr) {
                cout << current -> key; 
                if (current -> next != nullptr) cout << " ";
                current = current -> next; 
            }
            cout << "\n";
            return; 
        }
};

int main () {

    LinkedList LL; 

    LL.insertF(32);
    LL.insertF(42); 
    // LL.insertL(37);
    // LL.insertL(27);
    int temp = LL.deleteF();
    LL.printAll(); 

    return 0; 
}
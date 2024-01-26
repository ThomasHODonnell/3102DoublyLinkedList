#include <iostream> 
#include <list>

using namespace std; 

class Node {
    public: 
        int key; 
        Node* next;
        Node* prev; 

        Node () {
            key = 0; 
            next = prev = nullptr; 
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
            Node* newNode = new Node();
            newNode -> key = key;  
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
            Node* newNode = new Node();
            Node* current = tail; 
            newNode -> key = key; 
            if (count == 0) {
                head = tail = newNode; 
                newNode -> next = nullptr; 
                newNode -> prev = nullptr; 
            }
            else {
                current -> next = newNode; 
                newNode -> prev = current; 
                tail = newNode; 
                newNode -> next = nullptr; 
            }
            count++; 
            return; 
        }

        int deleteF () {
            Node* temp = head;
            int i = temp -> key;
            if (count == 0) return -1;
            if (temp -> next == nullptr) head = tail = nullptr;  
            else { head = head -> next; head -> prev = nullptr; }
            delete temp;
            count--; 
            return i; 
        }

        int deleteL () {
            Node* temp = tail;
            int i = temp -> key;
            if (count == 0) return -1;
            if (temp -> prev == nullptr) head = tail = nullptr;  
            else { tail = tail -> prev; tail -> next = nullptr; }
            delete temp;
            count--; 
            return i; 
        }

        void printAll () {
            Node* current = head;
            while (current != nullptr) {
                cout << current -> key; 
                if (current -> next != nullptr) cout << " ";
                else cout << "\n";

                current = current -> next; 
            }
            return; 
        }
};

int main () {

    LinkedList LL; 

    LL.insertF(32);
    LL.insertF(42); 
    LL.insertL(37);
    LL.insertL(27);
    int temp = LL.deleteF();
    LL.printAll();

    return 0; 
}
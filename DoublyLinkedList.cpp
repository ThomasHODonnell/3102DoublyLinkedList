#include <iostream> 

using namespace std; 

class Node {
    public: 
        int key; 
        Node* next;
        Node* prev; 

        Node (int key) {
            key = key; 
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

        // insert @ head
        void insertF (int key) {
            Node* newNode = new Node(key); 
            Node* temp = head; 
            if (count == 0) {
                head = tail = newNode; 
                newNode -> next = nullptr; 
                newNode -> prev = nullptr; 
            }
            else {
                 newNode -> next = head;
                 temp = head; 
                 temp -> prev = newNode;  
                 head = newNode;
                 newNode -> prev = nullptr; 
            }
            count++;
            return;
        }

        void insertL (int key) {

            return; 
        }

        int deleteF () {
            if (count == 0) return -1;  
            Node* temp = head; 
            head = head -> next; 
            delete temp; 
            head -> prev = nullptr; 
            return; 
        }


};



int main () {

    return 0; 
}
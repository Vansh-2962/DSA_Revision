#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }

        // TRAVERSING SINGLY LINKED LIST
        void traverse(Node* head){
            Node* temp = head;
            while(temp != NULL){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }

        // INSERTION AT THE BEGINNING
        void insertAtBeginning(Node* &head, int val){
            Node* newNode = new Node(val);
            newNode -> next = head;
            head = newNode;
        }

        // INSERTION AT THE END
        void insertAtEnd(Node* &head, int val){
            Node* newNode = new Node(val);
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }

        // DELETION OF A VALUE
        void deleteNode(Node* &head, int val){
            if(!head) return;
            if(head -> data == val){
                Node* temp = head;
                head = head -> next;
                delete temp;
                return;
            }

            Node* temp = head;
            while(temp -> next != NULL && temp -> next -> data != val){
                temp = temp -> next;                
            }
            if(temp -> next){
                Node* deletedNode = temp -> next;
                temp -> next = temp -> next -> next;
                delete deletedNode;
            }
        }
};  


int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head -> next = second;
    second -> next = third;

    head -> traverse(head);
    head -> insertAtBeginning(head, 0);
    head -> traverse(head);
    head -> insertAtEnd(head, 4);
    head -> traverse(head);
    head -> deleteNode(head, 2);
    head -> traverse(head);
    

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data= val;
            next = NULL;
            prev = NULL;
        }

        // FUNCTION TO INSERT NODE AT BEGINNING
        void insertAtBeginning(Node* &head, int val){
            Node* newNode = new Node(val);
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }

        // FUNCTION TO INSERT NODE AT END
        void insertAtEnd(Node* &head, int val){
            Node* newNode = new Node(val);
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> prev =temp;
        }

         // FUNCTION TO DELETE NODE
         void deleteNode(Node* &head, int val){
            if(!head) return;
            Node* temp = head;
            while(temp -> next != NULL && temp -> next -> data != val){
                temp = temp -> next;
            }
            if(!temp) return;
            if(temp -> prev) temp -> prev -> next = temp -> next;
            if(temp -> next) temp -> next -> prev = temp -> prev;
            if(temp == head) head = temp -> next;
            delete temp;
         }
         
};




int main(){

    return 0;
}
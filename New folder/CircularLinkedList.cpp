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

        // INSERT AT END
        void insertAtEnd(Node* &head, int val){
            if(head == NULL){
                head = new Node(val);
                head -> next = head;
                return;
            }

            Node* newNode = new Node(val);
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = head;
        }

        // INSERT AT BEGINNING OF CIRCULAR LINKED LIST
        void insertAtBeginning(Node* &head, int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = newNode;
                head -> next = head;
                return;
            }


            Node* temp = head;
            while(temp -> next != head){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = head;
            head = newNode;
        }

        // DELETE A NODE
        void deleteNode(Node* &head, int val){
            if(head == NULL) return;

            if(head -> data == val && head -> next == head){
                delete head;
                head = NULL;
                return;
            }

            Node* curr = head, *prev = NULL;
            
            if(curr -> data == val){
                while(curr -> next != head){
                    curr = curr -> next;
                }
                curr -> next = head -> next;
                delete head;
                head = curr -> next;
                return;
            }

            while(curr -> next != head && curr -> data != val){
                prev = curr;
                curr = curr -> next;
            }
            if(curr -> data == val){
                prev -> next = curr -> next;
                delete curr;
            }
        }

        // TRAVERSE
        void traverse(Node* head){
            if(head == NULL){
                cout << "Empty List" << endl;
                return;
            }

            Node* temp = head;
            do{
                cout << temp -> data << " ";
                temp = temp -> next;
            }while(temp != head);
        }


};



int main(){

    return 0;
}


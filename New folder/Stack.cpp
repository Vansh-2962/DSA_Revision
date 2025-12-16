#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Stack{
    public:
        int top;
        int* arr;
        int capacity;
        Stack(int size){
            top = -1;
            capacity = size;
            arr = new int[size];
        }

        ~Stack(){
            delete[] arr;
        }


        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top == capacity - 1;
        }

        void push(int val){
            if(isFull()){
                cout << "Stack is full" << endl;
                return;
            }
            arr[++top] = val;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is Empty"<<endl;
                return -1;
            }
            return arr[top--];
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack is Empty"<<endl;
                return -1;
            }
            return arr[top];
        }

};


int main(){

    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Peek element : " << s.peek() << endl;
    s.pop();
    cout << "Peek element : " << s.peek() << endl;
    return 0;
}
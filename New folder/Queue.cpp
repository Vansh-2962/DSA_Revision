#include<iostream>
using namespace std;

class Queue{
    public:
        int capacity;
        int *arr;
        int front;
        int rear;

        Queue(int size){
            capacity = size;
            arr = new int[size];
            front = rear = -1;
        }

        ~Queue(){
            delete[] arr;
        }

        bool isEmpty(){
            return front == -1 && rear == -1;
        }

        bool isFull(){
            return rear == capacity - 1;
        }

        void enqueue(int val){
            if(isFull()){
                cout << "Queue is full" << endl;
                return;
            }

            if(isEmpty()){
                front = 0;
            }

            arr[++rear] = val;
        }

        int dequeue(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }

            int removed = arr[front];
            if(front == rear){
                front = rear = -1;
            }else{
                front++;
            }

            return removed;
        }

        int frontElement(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[front];
        }

};



int main(){
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Removed element: " << q.dequeue() << endl;

    cout << "First element: " << q.frontElement() << endl;

    return 0;
}
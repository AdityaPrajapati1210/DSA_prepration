#include<iostream>
using namespace std;

int front = -1;
int rear = -1;
int n = 5;

void enqueue(int *arr, int data){
    // check full
    if((rear + 1) % n == front){
        cout<<"Queue Full"<<endl;
        return;
    }

    if(front == -1){ // first element
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % n;
    }

    arr[rear] = data;
}

void dequeue(int *arr){
    if(front == -1){
        cout<<"Queue Empty"<<endl;
        return;
    }

    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % n;
    }
}

void print(int *arr){
    if(front == -1){
        cout<<"Empty"<<endl;
        return;
    }

    int i = front;
    while(true){
        cout<<arr[i]<<" ";
        if(i == rear) break;
        i = (i + 1) % n;
    }
    cout<<endl;
}

int main(){
    int arr[5];

    enqueue(arr,1);
    enqueue(arr,2);
    enqueue(arr,3);
    enqueue(arr,4);
    enqueue(arr,5);

    print(arr);

    dequeue(arr);
    dequeue(arr);

    print(arr);

    enqueue(arr,6);
    enqueue(arr,7);

    print(arr);
}
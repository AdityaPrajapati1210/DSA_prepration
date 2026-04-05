#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(){

    }
    Node(int data){
        this->data = data;
        next = NULL;
    }


};

class ll{
    public:
    Node*head = NULL;
    Node*tail = NULL;

    void enqueue(int data){
        Node*newnode = new Node(data);
        if(head==NULL){
            head = tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void dequeue(){
        if(head == NULL){
            return;
        }else{
            Node*del = head;
            head = head->next;
            delete del;
        }
    }

    void print(){
        Node*temp = head;
        while(temp != NULL){
            cout << temp->data<<" ";
            temp = temp->next;
        }
    }
};


int main(){
    ll obj;
    obj.enqueue(20);
    obj.enqueue(10);
    obj.enqueue(10);
    obj.enqueue(10);
    obj.dequeue();
    obj.print();
}
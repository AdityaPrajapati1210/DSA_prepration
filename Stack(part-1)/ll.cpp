#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class Stack{
    public:
    Node*head = NULL;

    void push(int data){
        Node*newnode = new Node(data);
        if(head == NULL){
            head = newnode;
        }else{
            Node*temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }

    void pop(){
        if(head == NULL){
            cout <<"Stack is underflow"<<endl;
            return;
        }else if(head->next == NULL){
            Node*temp = head;
            head = NULL;
            delete temp;

        }else{
            Node*temp = head;
            Node*prev = NULL;
            
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
    }

    void print(){
        Node*temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

int main(){
    Stack s;
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.pop();
    s.print();
}
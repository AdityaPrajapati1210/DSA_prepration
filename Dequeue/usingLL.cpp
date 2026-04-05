#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class ll{
    public:
    Node*head = NULL;
    Node*tail = NULL;

    void push_back(int data){
        Node*newnode = new Node(data);
        if(head == NULL){
            head = tail = newnode;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

    }

    void push_front(int data){
        Node*newnode = new Node(data);
        if(head == NULL){
            head = tail = newnode;
        }else{
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "Empty"<<endl;
        }else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node *del = head;
            head = head->next;
            head->prev = NULL;
            delete del;
        }
    }

    void pop_back(){
        if(head == NULL){
            cout << "Empty"<<endl;
        }else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node *del = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete del;
        }
    }

    int front(){
        if(head == NULL){
            cout << "Empty"<<endl;
            return -1;
        }else{
            return head->data;
        }
    
    }
    int back(){
        if(head == NULL){
            cout << "Empty"<<endl;
            return -1;
        }else{
            return tail->data;
        }
    
    }

    void print(){
        Node *temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout <<endl;
    }
};


int main(){
    ll d;
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    d.push_back(7);
    d.push_front(3);
    d.push_front(2);
    d.push_front(1);
    d.push_front(0);
    d.print();
    d.pop_back();
    d.pop_front();
    d.print();
}


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class List{
    public:
    Node *head = NULL;

    void pushfront(int val){
        Node *newnode = new Node(val);
        if(head == NULL){
            head = newnode;
        }else{
            newnode->next = head;
            head = newnode;
        }
    }

    void pushback(int val){
        Node *newnode = new Node(val);
        if(head == NULL){
            newnode = head;
        }else{
            Node*temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newnode->next = NULL;
            temp->next = newnode;
        }
    }


    // INS

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};




int main(){
   List abc;
   abc.pushfront(10);
   abc.pushfront(20);
   abc.pushback(20);
   abc.print();

    return 0;
}
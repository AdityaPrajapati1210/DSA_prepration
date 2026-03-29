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
    ~Node(){
        cout<<"Node"<<data<<endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
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


    // Insert in the middle
    void insertpos(int val,int pos){
        Node*newnode  = new Node(val);
        if(pos == 1){
            newnode->next = head;
            head  = newnode;
            return;

        }
        Node*temp = head;
        while(pos > 1){
            temp = temp->next;
            pos--;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }


    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }


    void popfront(){
        
    }

    ~List(){
        cout<<"list"<<endl;
        if(head != NULL){
            delete head;
            head = NULL;
        } 
    }
};




int main(){
   List abc;
   abc.pushfront(10);
   abc.pushfront(20);
   abc.pushback(20);
   abc.insertpos(30,3);
   abc.pushback(20);
   abc.print();

    return 0;
}
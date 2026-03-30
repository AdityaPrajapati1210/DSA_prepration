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

    void pushback(int val){
        Node *newnode = new Node(val);

        if(head == NULL){
            head = newnode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void deleteNth(int pos){
        if(head == NULL) return;

        int length = 0;
        Node* temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        if(pos > length){
            cout << "Invalid position\n";
            return;
        }

        if(pos == length){
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        temp = head;
        for(int i = 1; i < length - pos; i++){
            temp = temp->next;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};

int main(){
   List abc;

   abc.pushback(10);
   abc.pushback(20);
   abc.pushback(30);
   abc.pushback(40);
   abc.pushback(50);

   abc.print();

   abc.deleteNth(2);   // delete 2nd node from end (40)

   abc.print();

   return 0;
}
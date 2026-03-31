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

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    
};

bool detectCycle(Node *head){
    Node*slow = head;
    Node*fast = head;

    
    while(slow != fast ){
        slow = slow->next;
        fast = fast->next->next;
        if(fast->next == NULL || fast->next->next == NULL){
            return false;
        }
    }
    return true;
}



int main(){
   Node*first = new Node(10);
   Node*second = new Node(20);
   Node*third = new Node(30);
   Node*fourth = new Node(40);
   
   first->next = second;
   second->next = third;
   third->next = fourth;
   fourth->next = second;   


   cout << detectCycle(first) << endl;

    return 0;
}
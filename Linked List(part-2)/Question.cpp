// Question 2 :Delete N Nodes After M Nodes of a Linked List

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
        cout << "NULL"<<endl;
    }


    void deleteNodes(int n , int m){
        Node*temp = head;
        Node*prev = NULL;
        for(int i=0;i<n ;i++){
            prev = temp;
            temp = temp->next;
            if(!temp){
                cout<<"linked list is Short"<<endl;
                return;
            }
        }

        for(int i=0;i<m;i++){
            Node*del = temp;
            prev->next = del->next;
            temp = temp->next;
            delete del;
            if(!temp){
                cout<<"linked list is Short"<<endl;
                return;
            }
        }
    }

    
};


int main(){
    List ll;
    ll.pushfront(50);
    ll.pushfront(40);
    ll.pushfront(30);
    ll.pushfront(20);
    ll.pushfront(10);
    ll.print();

    


    int n , m;
    cout<<"Enter the No. of nodes skip : ";
    cin>>n;
    cout<<"Enter the No. of nodes can delete : ";
    cin>>m;

    ll.deleteNodes(n,m);
    ll.print();
}
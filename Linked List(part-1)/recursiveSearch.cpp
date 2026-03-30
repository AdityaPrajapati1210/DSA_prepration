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
    // ~Node(){
    //     cout<<"Node"<<data<<endl;
    //     if(next != NULL){
    //         delete next;
    //         next = NULL;
    //     }
    // }
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
        Node* temp = head;
        if(head != NULL){
            head = head->next;
            delete temp;
        }  
    }
    void popback(){
        Node* temp = head;
        if(head != NULL){
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            Node *last = temp->next;
            temp->next = NULL;
            delete last;
        }  
    }


    int search(int val){
        if(head == NULL){
            return -1;
        }
        Node*temp = head;
        int count = 1;
        while(temp != NULL){
            if(temp->data == val){
                return count;
            }
            count++;
            temp = temp->next;
        }
        return -1;
    }

    // recursive search
    int searchRec(Node *head,int pos,int target){
        // base case
        if(head == NULL){
            return -1;
        }

        if(head->data == target){
            return pos;
        }else{
            return searchRec(head->next,pos+1,target);
        }
    }

};




int main(){
   List abc;
   abc.pushfront(10);
   abc.pushfront(20);
   abc.pushfront(30);
   abc.pushfront(40);
   cout<< abc.searchRec(abc.head,1,40)<<endl;

   abc.print();

    return 0;
}
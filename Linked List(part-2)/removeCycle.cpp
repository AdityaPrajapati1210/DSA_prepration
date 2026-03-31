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

    
    
};

void print(Node*head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}
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
};


void removeCycle(Node* head){
    if(head == NULL) return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: detect cycle
    bool hasCycle = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            hasCycle = true;
            break;
        }
    }

    if(!hasCycle) return;

    // Step 2: find start of cycle
    slow = head;
    if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }

    Node* prev = NULL;
    while(slow != fast){
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    // Step 3: remove cycle
    prev->next = NULL;
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
   removeCycle(first);
   print(first);

    return 0;
}
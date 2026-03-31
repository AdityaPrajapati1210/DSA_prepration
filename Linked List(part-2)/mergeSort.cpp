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

// 🔹 Find middle (slow-fast)
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// 🔹 Merge two sorted lists
Node* merge(Node* left, Node* right){
    if(!left) return right;
    if(!right) return left;

    Node* result = NULL;

    if(left->data <= right->data){
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// 🔹 Merge Sort
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Step 1: Split
    Node* mid = getMid(head);
    Node* right = mid->next;
    mid->next = NULL;

    // Step 2: Sort both halves
    Node* left = mergeSort(head);
    right = mergeSort(right);

    // Step 3: Merge
    return merge(left, right);
}

// 🔹 Print
void print(Node* head){
    while(head){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(50);
    head->next->next = new Node(40);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(30);

    cout << "Before: ";
    print(head);

    head = mergeSort(head);

    cout << "After: ";
    print(head);
}
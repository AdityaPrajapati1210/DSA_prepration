#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node*right;


    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};


Node*insert(Node*root , int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left , val);
    }else{
        root->right = insert(root->right , val);
    }

    return root;
}

Node* builtTree(int *arr , int n){
    Node*root = NULL;

    for(int  i=0;i<n;i++){
        root = insert(root , arr[i]);
    }
    return root;
}

void inorder(Node*root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);
}

int main(){
    int arr[] = {5,3,6,2,7,9,1,8};
    int n = sizeof(arr)/sizeof(int);

    Node *root = builtTree(arr,n);
    inorder(root);
}
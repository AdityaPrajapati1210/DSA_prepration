#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data  = data;
    }
};

void level(Node*root){
    if(root == NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }


}

Node* buildTree(int *arr,int start , int end){
    if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;

    Node*curr = new Node(arr[mid]);
    curr->left = buildTree(arr,start ,mid-1);
    curr->right = buildTree(arr,mid+1 ,end);
    return curr;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    Node*root = buildTree(arr,0,n-1);
    level(root);
}
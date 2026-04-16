#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data  = data;
        left = right = NULL;
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

Node* buildTree(vector<int>arr,int start , int end){
    if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;

    Node*curr = new Node(arr[mid]);
    curr->left = buildTree(arr,start ,mid-1);
    curr->right = buildTree(arr,mid+1 ,end);
    return curr;
}

void sorted(Node*root,vector<int>&arr){
    if(root == NULL){
        return;
    }

    sorted(root->left ,arr);
    arr.push_back(root->data);
    sorted(root->right ,arr);
}

int main(){
    Node*Bst = new Node(5);
    Bst->left = new Node(4);
    Bst->right = new Node(6);
    Bst->left->left = new Node(3);
    Bst->right->right = new Node(7);
    Bst->left->left->left = new Node(2);
    Bst->right->right->right = new Node(8);


    vector<int>arr;
    sorted(Bst,arr);
    int n = arr.size();
    Node*root = buildTree(arr,0,n-1);
    level(root);
}
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
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


pair<int, int> miinimumDiff(Node*root ,int k){
    if(root == NULL){
        return {NULL,0};
    }

    pair<int,int> l = miinimumDiff(root->left , k);
    pair<int,int> r = miinimumDiff(root->right , k);

    int diff = abs(root->data - k);
    return {root ,max(diff,max(l,r))};
    
}


int main(){
    Node*root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    int  k = 56;
    pair<int,int> ans = miinimumDiff(root ,k);
    cout<<ans.first->data<<endl;
}
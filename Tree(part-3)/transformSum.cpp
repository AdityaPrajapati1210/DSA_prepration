#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int transform(Node*root){
    if(root == NULL){
        return 0;
    }

    int l = transform(root->left);
    int r = transform(root->right);


    int currold = root->data;
    root->data = l + r;
    if(root->left){
        root->data+=root->left->data;
    }
    if(root->right){
        root->data+=root->right->data;
    }

    return currold;
}

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
    cout<<endl;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);


    int ans = transform(root);
    level(root);
    
}
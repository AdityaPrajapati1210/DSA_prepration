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



void kth_level(Node*root , int k , int level){
    if(root == NULL){
        return;
    }
    if(level == k){
        cout << root->data << " ";
        return;
    }

    kth_level(root->left,k,level+1);
    kth_level(root->right,k,level+1);

    
    
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);


    kth_level(root , 3,1);
}
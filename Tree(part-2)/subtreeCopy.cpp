#include<iostream>
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

bool identical(Node*root , Node*subtree){
    if(root == NULL && subtree == NULL){
        return true;
    }else if(root == NULL || subtree == NULL){
        return false;
    }

    if(root->data != subtree->data){
        return false;
    }

      
    return identical(root->left , subtree->left) && identical(root->right , subtree->right);

    
}


bool Checksubtree(Node*root , Node*subtree){
    if(root == NULL && subtree == NULL){
        return true;
    }else if(root == NULL || subtree == NULL){
        return false;
    }
    if(root->data == subtree->data){
        // idnentical
        if(identical(root,subtree)){
            return true;
        }
    }

    int left = Checksubtree(root->left , subtree);
    if(!left){
        return Checksubtree(root->right , subtree);
    }

    return true;
}

int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);


     Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout << Checksubtree(root ,subRoot);
}
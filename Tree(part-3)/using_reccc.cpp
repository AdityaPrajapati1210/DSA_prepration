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


Node* lowestanster(Node*root , Node*n1 , Node*n2){
    if(root == NULL){
        return NULL;
    }

    if(root == n1||root == n2){
        return root;
    }
    Node* l = lowestanster(root->left,n1,n2);
    Node* r = lowestanster(root->right,n1,n2);
    if(l && r){
        return root;
    }
    if(l)return l;
    if(r)return r;
    return NULL;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);


    cout << lowestanster(root ,root->left->left,root->right->right)->data<<" ";
}
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
bool rootToPath(Node*root , Node* n,vector<int>&path){
    if(root == NULL){
        return false;
    }

    if(root == n){
        return true;
    }
    path.push_back(root->data);
    bool isLeft = rootToPath(root->left,n,path);
    bool isRight = rootToPath(root->right,n,path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
};

int lowestanster(Node*root , Node*n1 , Node*n2){
    vector<int>path1;
    vector<int>path2;

    rootToPath(root ,n1 ,path1);
    rootToPath(root ,n2 ,path2);
    int level = -1;
    for(int i =0;i<path1.size();i++){
        if(path1[i] != path2[i]){
            return level;
        }else{
            level = path1[i];
        }
    }
    return level;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);


    cout << lowestanster(root ,root->left->left,root->left->right)<<" ";
}
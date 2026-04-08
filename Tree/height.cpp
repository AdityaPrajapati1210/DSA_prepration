#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* preorder(vector<int>vec){
    static int idx = -1;
    idx++;
    if(idx<vec.size() && vec[idx] == -1){
        return NULL;
    }

    Node*currnode = new Node(vec[idx]);
    currnode->left = preorder(vec);
    currnode->right = preorder(vec);
    return currnode;
}


int height(Node*root){
    if(root == NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    int h = max(l,r)+1;
    return h;
}


int main(){
    vector<int>vec = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*root = preorder(vec);
    cout << height(root);

}
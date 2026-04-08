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

Node*postorder(vector<int>vec){
    static int idx = -1;
    idx++;
    if(idx<vec.size() && vec[idx] == -1){
        return NULL;
    }

    Node*currnode;
    currnode->left = preorder(vec);
    currnode->right = preorder(vec);
    currnode = new Node(vec[idx]);
    return currnode;
}

void printPostorder(Node*tree){
    if(tree == NULL){
        return;
    }
    printPostorder(tree->left);
    printPostorder(tree->right);
    cout<<tree->data<<" ";
}

int main(){
    vector<int>vec = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*tree = preorder(vec);
    printPostorder(tree);

}
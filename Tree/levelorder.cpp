#include<iostream>
#include<vector>
#include<queue>
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

int main(){
    vector<int>vec = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*tree = preorder(vec);
    level(tree);

}
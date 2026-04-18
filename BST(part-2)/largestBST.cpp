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


class Info{
    public:
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBST,int min,int max,int size){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

static int maxsize;
static Node*maxBST;
Info*largestBST(Node*root){
    if(root == NULL){
        return new Info(true ,INT8_MAX,INT8_MIN,0);
    }

    Info* l = largestBST(root->left);
    Info* r = largestBST(root->right);

    int currmin = min(root->data , min(l->min , r->min));
    int currmax = max(root->data , max(l->max , r->max));

    int currsize = l->size + r->size +1;

    if(l->isBST && r->isBST && root->data > l->max && root->data < r->min) {
        maxsize = max(maxsize,currsize);
        maxBST = root;
        return new Info(true,currmin,currmax,currsize);
    }
    return new Info(false,currmin,currmax,currsize);
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

    // level(root);
    largestBST(root);
    cout << "max size: " << maxsize<<endl;
    cout << "max BST: " << maxBST->data<<endl;
    // ok my sessional is started so i could go 
}
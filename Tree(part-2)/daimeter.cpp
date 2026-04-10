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

Node*preorder(vector<int>vec){
    static int idx = -1;
    idx++;
    if(vec[idx] == -1){
        return NULL;
    }

        Node *newnode = new Node(vec[idx]);
        newnode->left = preorder(vec);
        newnode->right = preorder(vec);

        return newnode;   
};
int height(Node*root){
    if(root == NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    int h = max(l,r)+1;
    return h;
}

int daimeter(Node*root){
    if(root == NULL){
        return 0;
    }
    int currdaimeter =  height(root->left) + height(root->right) +1;

    int leftSub = daimeter(root->left);
    int rightSub = daimeter(root->right);

    int temp = max(leftSub,rightSub);
    return max(currdaimeter,temp);
}

pair<int ,int> dai2(Node*root){
    if(root == NULL){
        return {0,0};
    }

    pair<int , int>leftD = dai2(root->left);
    pair<int , int>rightD = dai2(root->right);
    // (D , H)

    int currD = leftD.second + rightD.second + 1;
    int finalD = max(currD , max(leftD.first , rightD.first));

    int finalH  = max(leftD.second , rightD.second) + 1;

    return {finalD , finalH};
 

}


int main(){
    vector<int>vec = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*root = preorder(vec); 
    cout << dai2(root).first<<" "<<dai2(root).second<<endl;

}
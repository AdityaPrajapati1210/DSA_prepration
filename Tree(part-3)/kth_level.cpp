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


vector<int> kth_level(Node *root , int k) {
    // code here
        queue<Node*>q;
        vector<int>ans;
        
        q.push(root);
        int count = 0;
        
        while(!q.empty()){
            count++;
            int size = q.size();

            for(int i =0;i<size;i++){
                Node* curr = q.front();
                q.pop();

                if(count == k){
                    ans.push_back(curr->data);
                }
                
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return ans;     
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);


    vector<int>ans = kth_level(root , 3);
    for(int i : ans){
        cout<<i<<" ";
    }
        cout<<endl;
}
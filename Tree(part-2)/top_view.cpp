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


vector<int> topView(Node *root) {
    // code here
        queue<pair<Node* , int>>q;
        map<int ,int>m;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            Node* currNode = curr.first;
            int currhd = curr.second;
            
            if(m.count(currhd) == 0){
                m[currhd] = currNode->data;
            }
            
            if(currNode->left){
                q.push({currNode->left , currhd-1});
            }
            
            if(currNode->right){
                q.push({currNode->right , currhd+1});
            }
        }
        vector<int>ans;
        for(auto it : m){
            ans.push_back(it.second);
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


    vector<int>ans =  topView(root);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
}
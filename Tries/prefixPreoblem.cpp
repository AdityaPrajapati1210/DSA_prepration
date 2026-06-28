#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
public:

    unordered_map<char,Node*>children;
    bool endofchar;
    int freq;

    Node(){
        endofchar = false;
        freq = 0;
    }
};

class Tries{
public:

    Node*root;

    Tries(){
        root = new Node();
    }

    void insert(string key){
        Node*temp = root;

        for(char i : key){
            if(temp->children.count(i) == 0){
                temp->children[i] = new Node();
            }
            temp = temp->children[i];
            temp->freq++;
        }
        temp->endofchar = true;
    }

    bool search(string key){
        Node*temp = root;

        for(char i : key){
            if(temp->children.count(i) == 0){
                return false;
            }else{
                temp = temp->children[i];
            }

        }
        return temp->endofchar;
    }

    vector<string>prefixs(vector<string> &arr){
        vector<string>ans;
        
        for(string key: arr){
            Node * temp = root;
            temp = temp->children[key[0]];

            for(int j=1;j<key.length();j++){
                if(temp->freq > 1){
                    temp = temp->children[key[j]];
                }else{
                    ans.push_back(key.substr(0,j));
                    break;
                }
            }
        }

        return ans;
    }
};

int main(){

    vector<string> arr = {
        "zebra",
        "dog",
        "duck",
        "dove"
    };

    Tries tries;

    for(string i : arr){
        tries.insert(i);
    }

    vector<string> ans = tries.prefixs(arr);

    for(string i : ans){
        cout << i << " ";
    }

    return 0;
}
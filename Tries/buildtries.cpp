#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;


class Node{
public:
    unordered_map<char, Node*>children;
    bool endofchar;

    Node(){
        endofchar = false;
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

        for(int i=0;i<key.length();i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();  //insert
            }
            temp = temp->children[key[i]];
        }
        temp->endofchar = true;
    }

    bool search(string key){
        Node* temp = root;

        for(int i=0;i<key.length();i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }
        }
        if(temp->endofchar){
            return true;
        }
        return false;
    }
};

int main(){
    vector<string>vec = {"the" ,"a", "there","their","and","air"};
    Tries trie;
    for(auto i : vec){
        trie.insert(i);
    }

    cout << trie.search("theii");
}
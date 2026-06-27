#include<iostream>
#include<unordered_map>
#include<string>
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
                temp->children[key[i]] == new Node();  //insert
            }
            temp = temp->children[key[i]];
        }
        temp->endofchar = true;
    }
};

int main(){
    
}
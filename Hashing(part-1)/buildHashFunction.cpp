#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node*next;

    Node(string key,int val){
        this->key = key;
        this->val = val;
        Node*next = NULL;
    }
};

class HashFunc{
    int totsize;
    int currsize;
    Node**table;
public:

    HashFunc(int size){
        totsize = size;
        currsize = 0;

        table = new Node*[size];

        for(int i=0;i<size;i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){

    }

    void eraise(string key){

    }

    void find(string key){

    }
};

int main(){
    HashFunc obj(5);
    obj.insert("Adiyta",20);
    obj.find("Aditya");
    obj.eraise("Adiyta");

}
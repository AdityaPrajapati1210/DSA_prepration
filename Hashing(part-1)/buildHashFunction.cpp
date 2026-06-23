#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

list<int>ll;

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

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashFunc{
    int totsize;
    int currsize;
    Node**table;

    int HashFunction(string key){
        int n = key.length();

        int idx= 0;
        for(int i=0;i<n;i++){
            idx += (key[i] * key[i])%totsize;
        }
        return idx;

    }
public:

    HashFunc(int size){
        totsize = size;
        currsize = 0;

        table = new Node*[size];

        for(int i=0;i<size;i++){
            table[i] = NULL;
        }
    }


    void rehash(){
        Node**oldtable = table;
        int oldsize = totsize;

        table = new Node*[2*totsize];

        for(int i=0;i<oldsize;i++){
            table[i] = NULL;
        }

        for(int i=0;i<oldsize;i++){
            Node*temp = oldtable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldtable[i] != NULL){
                delete oldtable[i];
            }
        }
        delete [] oldtable;
    }

    void insert(string key, int val){
        int idx = HashFunction(key);

        Node* newNode = new Node(key ,val);
        Node* head = table[idx];

        newNode->next = head;
        newNode = head;

        currsize++;


        int lamda = currsize/(double)totsize;
        if(lamda > 1){
            rehash();
        }
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
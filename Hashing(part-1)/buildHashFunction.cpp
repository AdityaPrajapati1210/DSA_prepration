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
        this->next = NULL;
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
            idx = (idx + key[i] * key[i])%totsize;
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
        totsize = 2*totsize;

        table = new Node*[totsize];

        for(int i=0;i<totsize;i++){
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
        table[idx] = newNode;

        currsize++;


        double lamda = currsize/(double)totsize;
        if(lamda > 1){
            rehash();
        }
    }

    bool exists(string key){
        int idx = HashFunction(key);

        Node*temp = table[idx];
        while (temp != NULL){
            if(temp->key == key){
                return true;
            }
            temp= temp->next;
        }
        return false;
    }

    void eraise(string key){
        if(exists(key)){
            int idx = HashFunction(key);
            Node *temp = table[idx];
            Node*prev = NULL;
            while (temp != NULL){
                if(temp->key == key){
                    if(prev == NULL){
                        table[idx] = temp->next;
                    }else{
                        prev->next = temp->next;
                    }
                    temp->next = NULL;
                    delete temp;
                    break;
                }
            prev = temp;
            temp= temp->next;
            }
        }
    }

    int search(string key){
        if(exists(key)){

            int idx = HashFunction(key);

            Node*temp = table[idx];
            while (temp != NULL){
                if(temp->key == key){
                    return temp->val;
                }
                temp= temp->next;
            }
        }
        return -1;
    }
};

int main(){
    HashFunc obj(5);
    obj.insert("Aditya",20);
    cout<<obj.search("Aditya");
    // obj.eraise("Adiyta");

    

}
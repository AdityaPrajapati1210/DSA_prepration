#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

    class Node {
    public:
        unordered_map<char, Node*> children;
        bool endofchar;
        int freq;

        Node() {
            endofchar = false;
            freq = 0;
        }
    };

    class Tries {
    public:
        Node* root;

        Tries() {
            root = new Node();
        }

        void insert(string key) {
            Node* temp = root;

            for(char ch : key) {
                if(temp->children.count(ch) == 0) {
                    temp->children[ch] = new Node();
                }

                temp = temp->children[ch];
                temp->freq++;
            }

            temp->endofchar = true;
        }

        vector<string> prefixs(vector<string>& arr) {
            vector<string> ans;

            for(string key : arr) {
                Node* temp = root;
                string prefix = "";

                for(char ch : key) {
                    prefix += ch;
                    temp = temp->children[ch];

                    if(temp->freq == 1) {
                        ans.push_back(prefix);
                        break;
                    }
                }
                if(temp->freq > 1){
                    ans.push_back(key);
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
class Solution {
public:

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
        Node * temp = root;

        for(int i=0;i<key.length();i++){
            if(temp->children.count(key[i]) == 0){
                return false;
            }
            temp = temp->children[key[i]];
        }
        return temp->endofchar;
    }
};
unordered_map<string,bool> dp;

bool wordbreak(string s, Tries &trie){

    if(s.empty()) return true;

    if(dp.count(s))
        return dp[s];

    for(int i=0;i<s.length();i++){

        string first = s.substr(0,i+1);
        string second = s.substr(i+1);

        if(trie.search(first) && wordbreak(second, trie)){
            return dp[s] = true;
        }
    }

    return dp[s] = false;
}


    bool wordBreak(string s, vector<string>& wordDict) {
        Tries trie;
        for(auto i : wordDict){
            trie.insert(i);
        }

        return wordbreak(s,trie);
    }
};
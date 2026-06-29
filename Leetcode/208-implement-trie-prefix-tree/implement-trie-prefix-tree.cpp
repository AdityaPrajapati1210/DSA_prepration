class Trie {
public:

    class Node{
        public:
        unordered_map<char,Node*>children;
        bool endofchar;

        Node(){
            endofchar = false;
        }
    };


    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*temp = root;

        for(char ch : word){
            if(temp->children.count(ch) == 0){
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }

        temp->endofchar = true;
    }
    
    bool search(string word) {
        Node*temp = root;

        for(char ch : word){
            if(temp->children.count(ch) == 0){
                return false;
            }else{
                temp = temp->children[ch];
            }
        }
        return temp->endofchar;
    };
    
    bool startsWith(string prefix) {
        Node*temp  = root;
         for(char ch : prefix){
            if(temp->children.count(ch) == 0){
                return false;
            }
            temp = temp->children[ch];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
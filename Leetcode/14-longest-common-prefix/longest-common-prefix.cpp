class Solution {
public:
    class Node{
        public:
        unordered_map<char,Node*>children;
        bool endofchar;


        Node(){
            endofchar = false;
        }
    };

    class Tries{
        public:

        Node* root;
        int numberofstr;

        Tries(){
            root = new Node();
        }

        void insert(string key){
            Node *temp = root;
            for(char ch : key){
                if(temp->children.count(ch) == 0){
                    temp->children[ch] = new Node();
                }
                temp = temp->children[ch];
            }
            temp->endofchar = true;
            numberofstr++;
        }

        bool search(string key){
            Node *temp = root;
            for(char ch : key){
                if(temp->children.count(ch) == 0){
                    return false;
                }
                temp = temp->children[ch];
            }
            return temp->endofchar;
        }

        string LCP() {
            string ans = "";
            Node* curr = root;

            while(curr->children.size() == 1 && !curr->endofchar) {
                auto it = curr->children.begin();

                ans += it->first;
                curr = it->second;
            }

            return ans;
        }


    };


    string longestCommonPrefix(vector<string>& strs) {
        Tries trie;
        for(string i : strs){
            trie.insert(i);
        }

        return trie.LCP();
    }
};
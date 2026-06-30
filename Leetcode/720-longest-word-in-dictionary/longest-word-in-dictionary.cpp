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

        Node*root;

        Tries(){
            root = new Node();
        }

        void insert(string key){
            Node*temp = root;
            for(char ch : key){
                if(temp->children.count(ch) == 0){
                    temp->children[ch] = new Node();
                }
                temp = temp->children[ch];
            }
            temp->endofchar = true;
        }


        bool search(string key){
            Node*temp = root;
            for(char ch : key){
                if(temp->children.count(ch) == 0){
                    return false;
                }else{
                    temp = temp->children[ch];
                }
            }
            return temp->endofchar;
        }

        void helper(Node*root,string &ans,string temp){
            for(pair<char,Node*> child : root->children){
                if(child.second->endofchar==true){
                        temp += child.first;

                    if(((temp.size() == ans.size()) && (temp < ans)) || temp.size() > ans.size()){
                        ans = temp;
                    }

                    helper(child.second,ans,temp);
                    temp = temp.substr(0,temp.size()-1);
                }
            }
        }

        string longestword(){
            string ans = "";
            helper(root,ans,"");
            return ans;
        }

    };

    string longestWord(vector<string>& words) {
        Tries trie;
        for(string i : words){
            trie.insert(i);
        }

        return trie.longestword();
    }
};
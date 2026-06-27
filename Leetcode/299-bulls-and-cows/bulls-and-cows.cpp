class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<int,int>mp;
        vector<int>vec;
        for(int i=0;i<secret.length();i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                mp[secret[i]]++;
                vec.push_back(guess[i]);
            }
        }

        for(int i=0;i<vec.size();i++){
            if(mp.count(vec[i]) != 0 && mp[vec[i]] != 0){
                cows++;
                mp[vec[i]]--;
            }
        }

        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans; 
    }
};
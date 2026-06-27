class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mp;
        vector<pair<int,int>>vec;

        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]) == 0){
                mp[nums[i]] = 1;
            }else{
                mp[nums[i]]++;
            }
        }

        for(auto i : mp){
            vec.push_back(make_pair(i.first,i.second));
        }

        sort(vec.begin(), vec.end(),
            [](pair<int,int> a, pair<int,int> b){

                if(a.second == b.second){
                    return a.first > b.first;
                }

                return a.second < b.second;
            });
        vector<int>ans;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].second;j++){
                ans.push_back(vec[i].first);
            }
        }


        return ans;
    }
};
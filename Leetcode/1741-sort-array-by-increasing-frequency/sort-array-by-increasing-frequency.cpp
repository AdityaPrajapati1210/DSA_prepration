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

        sort(nums.begin(), nums.end(),
            [&](int a, int b){

                if(mp[a] == mp[b]){
                    return a > b;
                }
                return mp[a] < mp[b];
            });


        return nums;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;

        for(int i=0;i<n;i++){
            if(freq.find(nums[i]) != freq.end()){
                freq[nums[i]]++;
            }else{
                freq[nums[i]] = 1;
            }
        }

        for(auto i : freq){
            if(i.second > 1){
                return true;
            }
        }

        return false;
    }
};
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size() == 1){
            return true;
        }
        int minimum = INT_MAX;
        int Even = true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] < minimum){
                minimum = nums1[i];
            }
            if(nums1[i]%2 == 1){
                Even = false;
            }
        }

        return Even || minimum % 2 == 1;

        
    }
};
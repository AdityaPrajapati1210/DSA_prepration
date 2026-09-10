class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        // nums[-1] = INT_MIN;
        // nums[n] = INT_MAX;

        while(low < high){
            int mid = low + (high - low)/2;

            if(nums[mid] < nums[mid+1]){
                low = mid+1;
            }else{
                high = mid;
            }
        }

        return low;
    }
};
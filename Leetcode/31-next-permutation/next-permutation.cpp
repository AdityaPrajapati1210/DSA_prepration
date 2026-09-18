class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int temp = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (temp > nums[i]) {
                for (int j = n - 1; j >= i;j--) {
                    if (nums[i] < nums[j]) {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        break;
                    }
                }
                break;
            }else if(i == 0){
                reverse(nums.begin(), nums.end());
                break;
            }
            temp = nums[i];
        }

    }
};
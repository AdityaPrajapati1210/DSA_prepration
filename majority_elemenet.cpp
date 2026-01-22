#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int curr = nums[0];
    for(int i = 0;i<n;i++){
        if(curr == nums[i]){
            count++;
            curr = nums[i];
        }else{
                
             if(count <= 1){
                 curr = nums[i];
                count == 1;
                }else{
                   count--;
            }
        }
    }
    return curr;
}

int main(){
    vector<int> nums = {2,2,4,5,2,2,2,8,8,8,8,88,8,8,88,8,8};
    int result = majorityElement(nums);
    cout<<result<<endl;
}
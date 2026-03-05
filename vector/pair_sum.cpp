#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    
    int low = 0;
    int high  = nums.size() -1;

    while(low <= high){
        if(nums[low] + nums[high] == target){
            cout << "Number is : " << low << " & " << high <<endl;
            break;
        }else if (nums[low] + nums[high] > target){
            high--;
        }else{
            low++;
        }
        
    }
}
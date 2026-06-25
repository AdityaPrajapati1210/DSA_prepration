#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxSubbarray(vector<int> arr ,int k) {
        // code here
        
        unordered_map<int,int>mp;
        int sum =0;
        int maxlength = 0;
        for(int j=0;j<arr.size();j++){
            sum+=arr[j];
            if(sum == k){
                maxlength = j+1;
            }
            if(mp.count(sum-k)){
                int length = j - mp[sum];
                maxlength = max(maxlength ,length);
            }else{
                mp[sum] = j;
            }
        }
        
        
        return maxlength;
}

int main(){
    vector<int>vec = {1,2,3};
    int k =3;

    cout<<maxSubbarray(vec,k);
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxSubbarray(vector<int> arr ,int k) {
        // code here
        
        unordered_map<int,int>mp;
        int sum =0;
        int ans = 0;
        mp[0]=1;
        for(int j=0;j<arr.size();j++){
            sum+=arr[j];

            if(mp.count(sum-k)){
                ans+=mp[sum-k];
            }

            if(mp.count(sum) == k){
                mp[sum]++;
            }else{
                mp[sum] = 1;
            }
        }
        
        return ans;
}

int main(){
    vector<int>vec = {1,2,3};
    int k =3;

    cout<<maxSubbarray(vec,k);
}
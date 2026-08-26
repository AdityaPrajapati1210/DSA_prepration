        #include<iostream>
        #include<vector>
        #include<set>
        #include<algorithm>
        using namespace std;

        int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        int m = nums2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        int ans =0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];  
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                ans = max(ans,dp[i][j]);
            }
        }

        return ans;
    }


        int main(){
            vector<int>nums1 = { 50,3,10,7,40,80};
            int n = nums1.size();
            set<int>s;
            for(int i=0;i<n;i++){
                s.insert(nums1[i]);
            }
            
            vector<int>nums2;
            for(int i : s){
                nums2.push_back(i);
            }
            sort(nums2.begin(),nums2.end());
        
            cout << findLength(nums1,nums2);






            
        }
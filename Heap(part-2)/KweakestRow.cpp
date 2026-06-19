#include<iostream>
#include<vector>
#include<queue>
using namespace std;
    class Pair{
        public:
        int count;
        int idx;

        Pair(int count , int idx){
            this->count = count;
            this->idx = idx;
        }

        bool operator < (const Pair &obj) const{
            if(this->count == obj.count){
                return this->idx > obj.idx;
            }
            return this->count > obj.count;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Pair>vec;

        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            vec.push_back(Pair(count,i));
        }

        priority_queue<Pair>pq;
        for(int i=0;i<vec.size();i++){
            pq.push(vec[i]);
        }
    vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().idx);
            pq.pop();
        }

        return ans;
    };


int main(){
    vector<vector<int>>vec = {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };

    vector<int>ans = kWeakestRows(vec,2);
    for(int i=0;i<ans.size();i++){
        cout << ans[i]<<" ";
    }
    cout<<endl;
};
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job {
    int id, dead, profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;   // sort by profit descending
}

pair<int,int> JobScheduling(vector<Job> &jobs) {
    
    sort(jobs.begin(), jobs.end(), cmp);

    // find max deadline
    int maxDead = 0;
    for(auto j : jobs){
        maxDead = max(maxDead, j.dead);
    }

    vector<int> slot(maxDead + 1, -1);

    int count = 0, totalProfit = 0;

    for(int i = 0; i < jobs.size(); i++){
        for(int j = jobs[i].dead; j > 0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                count++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {count, totalProfit};
}

int main(){
    vector<Job> jobs = {
        {0,3,50}, {1,1,10}, {2,2,20}, {3,2,30}
    };

    auto ans = JobScheduling(jobs);
    cout << "Jobs done: " << ans.first << endl;
    cout << "Max Profit: " << ans.second << endl;
}
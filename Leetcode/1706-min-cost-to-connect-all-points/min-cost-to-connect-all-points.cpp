class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool>mst(V,false);

        pq.push(make_pair(0,0));
        int minwt = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                minwt+=wt;

                for(int v=0;v<V;v++){
                    if(u != v){
                        int w = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                        pq.push(make_pair(w,v));
                    }
                }

            }
        }
        return minwt;
    }
};
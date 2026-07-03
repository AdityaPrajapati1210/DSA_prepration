class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        list<int> *l;
        l = new list<int>[n];

        for(auto edge : edges){
            l[edge[0]].push_back(edge[1]);
            l[edge[1]].push_back(edge[0]);
        }

        vector<bool>vis(n,false);
        queue<int>q;

        q.push(source);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == destination){
                return true;
            }

            for(int i : l[u]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        return false;
    }
};
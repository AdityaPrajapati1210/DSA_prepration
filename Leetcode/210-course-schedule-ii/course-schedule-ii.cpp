class Solution {
public:

    bool isCycle(int src,vector<int>&vis,vector<int>&rec,vector<vector<int>>& graph){
        vis[src] = true;
        rec[src] = true;

        for(int i=0;i<graph.size();i++){
            int u = graph[i][1];
            int v = graph[i][0];

            if(src == u){
                if(!vis[v]){
                    if(isCycle(v,vis,rec,graph)){
                        return true;
                    }
                }else{
                    if(rec[v]){
                        return true;
                    }
                }
            }
        }
        rec[src]=false;
        return false;
    }

    void helper(int src,vector<int>&vis,stack<int>&s,vector<vector<int>>& graph){
        vis[src] =true;

        for(int i=0;i<graph.size();i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(src == u){
                if(!vis[v]){
                    helper(v,vis,s,graph);
                }
            }
        }
        s.push(src);
    }



    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        int V = numCourses;
        vector<int>vis(V,false);
        vector<int>rec(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(i,vis,rec,prerequisites)){
                    return ans;
                }
            }
        }
        vis = vector<int>(V,false);
        stack<int>s;
        for(int i =0;i<V;i++){
            if(!vis[i]){
                helper(i,vis,s,prerequisites);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;

    }
};
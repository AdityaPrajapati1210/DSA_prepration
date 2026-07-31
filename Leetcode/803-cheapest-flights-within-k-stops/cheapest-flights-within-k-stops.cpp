class Solution {
public:
    class Info{
        public:
        int u;
        int cost;
        int stops;

        Info(int u,int cost,int stops){
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }

    };

    class Graph{
        public:
        int V;
        list<pair<int,int>>*l;

        Graph(int V){
            this->V = V;
            l = new list<pair<int,int>> [V];
        }

        void addEdge(int u, int v,int wt){
            l[u].push_back(make_pair(v,wt));
        }

        void helper(int V,int src,int k,vector<int>&dist){
            queue<Info>q;
            q.push(Info(src,0,-1));

            while(!q.empty()){
                Info curr = q.front();
                q.pop();

                for(auto v : l[curr.u]){
                    if(dist[v.first] > curr.cost + v.second && curr.stops < k){
                        dist[v.first] = curr.cost + v.second;
                        q.push(Info(v.first, dist[v.first],curr.stops+1));
                    }
                }
            }
        }
    };

    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Graph gh(n);
        for(int i=0;i<flights.size();i++){
            gh.addEdge(flights[i][0] , flights[i][1], flights[i][2]);
        }

        vector<int>dist(n,INT_MAX);

        gh.helper(n,src,k,dist);

        if(dist[dst] != INT_MAX){
            return dist[dst];
        }else{
            return -1;
        }
        

    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:times){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int cost_so_far=pq.top().first;
            pq.pop();
            for(auto v:adj[node]){
                int u=v.first;
                int cost=v.second;
                if(cost_so_far+cost<dist[u]){
                    dist[u]=cost_so_far+cost;
                    pq.push({dist[u],u});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

    }
};
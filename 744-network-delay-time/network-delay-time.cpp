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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int cost_sofar=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto v:adj[node]){
                int u=v.first;
                int cost=v.second;
                if(cost_sofar+cost<dist[u]){
                    dist[u]=cost_sofar+cost;
                    pq.push({dist[u],u});
                }
            }
        }
        dist[0]=0;
        int maxi=*max_element(dist.begin(),dist.end());
        if(maxi==INT_MAX){
            return -1;
        }
        return maxi;
    }
};

































//class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int,int>>>adj(n+1);
//         for(auto i:times){
//             int u=i[0];
//             int v=i[1];
//             int w=i[2];
//             adj[u].push_back({v,w});
//         }
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         vector<int>dist(n+1,INT_MAX);
//         pq.push({0,k});
//         dist[k]=0;
//         while(!pq.empty()){
//             int cost_sofar=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
//             for(auto v:adj[node]){
//                 int u=v.first;
//                 int cost=v.second;
//                 if(cost_sofar+cost<dist[u]){
//                     dist[u]=cost_sofar+cost;
//                     pq.push({dist[u],u});
//                 }
//             }
//         }
//         int ans=0;
//         for(int i=1;i<=n;i++){
//             ans=max(ans,dist[i]);
//         }
//         if(ans==INT_MAX){
//             return -1;
//         }
//         return ans;
//     }
// };
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










































// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int, int>>>adj(n+1);
//         for(auto i:times){
//             int u=i[0];
//             int v=i[1];
//             int w=i[2];
//             adj[u].push_back(make_pair(v,w));
//         }
//         vector<bool>ex(n+1,0);
//         vector<int>dist(n+1,INT_MAX);
//         dist[k]=0;
//         priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
//         pq.push({0,k});
//         while(!pq.empty()){
//             pair<int,int>temp=pq.top();
//             pq.pop();
//             int node=temp.second;
//             if(ex[node]==1){
//                 continue;
//             }
//             ex[node]=1;
//             for(int i=0;i<adj[node].size();i++){
//                 int nei=adj[node][i].first;
//                 int wt=adj[node][i].second;
//                 if(!ex[nei]&&dist[node]+wt<dist[nei]){
//                     dist[nei]=dist[node]+wt;
//                     pq.push({dist[nei],nei});
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



















//class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int, int>>>adj(n+1);
//         for(auto i:times){
//             int u=i[0];
//             int v=i[1];
//             int w=i[2];
//             adj[u].push_back({v,w});
//         }
//         int src=k;
//         int v=n;
//         vector<bool>explr(v+1,0);
//         vector<int>dist(v+1,INT_MAX);
//         dist[src]=0;
        
//         //select node which is unexplored yet and dist value in minimum
//         int count=v;
//         while(count--){
//             int node=-1;
//             int value=INT_MAX;
//             for(int i=1;i<=v;i++){
//                 if((!explr[i])&&value>dist[i]){
//                     value=dist[i];
//                     node=i;
//                 }
//             }
            
//             if (node == -1) break; // All remaining nodes are unreachable

//             explr[node] = true;
//             //relax the edges
//             for(int j=0;j<adj[node].size();j++){
//                 int neigh=adj[node][j].first;
//                 int wt=adj[node][j].second;
//                 if(!explr[neigh]&&dist[node]+wt<dist[neigh]){
//                     dist[neigh]=dist[node]+wt;
//                 }
//             }
//         }
//         int ans=INT_MIN;
//         for(int i=1;i<=v;i++){
//             ans=max(ans,dist[i]);
//         }
//         if(ans==INT_MAX){
//             return -1;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>>adj(n);
        for(auto i:roads){
            int a=i[0];
            int b=i[1];
            adj[a].insert(b);
            adj[b].insert(a);
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int ans=adj[i].size()+adj[j].size();
                if(adj[i].find(j)!=adj[i].end()){
                    ans=ans-1;
                }
                cnt=max(cnt,ans);
            }
        }
        return cnt;
    }
};
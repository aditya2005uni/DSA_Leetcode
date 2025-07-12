class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n);
        vector<vector<int>>adj(n,vector<int>(n,0));
        for(auto i:roads){
            int a=i[0];
            int b=i[1];
            deg[a]++;
            deg[b]++;
            adj[a][b]=1;
            adj[b][a]=1;
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int ans=deg[i]+deg[j];
                if(adj[i][j]==1){
                    ans=ans-1;
                }
                cnt=max(cnt,ans);
            }
        }
        return cnt;
    }
};
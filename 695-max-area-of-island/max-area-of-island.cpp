class Solution {
public:
void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &cnt){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0){
            return;
        }
        cnt++;
        grid[i][j]=0;
        dfs(grid,i+1,j,n,m,cnt);
        dfs(grid,i,j+1,n,m,cnt);
        dfs(grid,i-1,j,n,m,cnt);
        dfs(grid,i,j-1,n,m,cnt);
    }   
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    dfs(grid,i,j,n,m,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
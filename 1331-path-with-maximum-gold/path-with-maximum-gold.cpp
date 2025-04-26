class Solution {
    public:
    int fun(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 0;
        }
        //int ans=0;
        // ans=max(ans,fun(grid,i+1,j,m,n));
        // ans=max(ans,fun(grid,i+1,j,m,n));
        // ans=max(ans,fun(grid,i+1,j,m,n));
        // ans=max(ans,fun(grid,i+1,j,m,n));
        int temp=grid[i][j];
        grid[i][j]=0;
        int a=fun(grid,i+1,j,m,n);
        int b=fun(grid,i-1,j,m,n);
        int c=fun(grid,i,j+1,m,n);
        int d=fun(grid,i,j-1,m,n);
        grid[i][j]=temp;
        return temp+max({a,b,c,d});
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,fun(grid,i,j,m,n));
            }
        }
        return ans;
    }
};
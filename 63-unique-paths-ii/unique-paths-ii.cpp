class Solution {
    int fun(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || i>=m ||j<0 || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int r=fun(i,j+1,m,n,obstacleGrid,dp);
        int d=fun(i+1,j,m,n,obstacleGrid,dp);
        return dp[i][j]=r+d;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=fun(0,0,m,n,obstacleGrid,dp);
        return ans;
    }
};
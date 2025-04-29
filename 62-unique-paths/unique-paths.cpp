class Solution {
    int fun(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || i>=m ||j<0 || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int r=fun(i,j+1,m,n,dp);
        int d=fun(i+1,j,m,n,dp);
        return dp[i][j]=r+d;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=fun(0,0,m,n,dp);
        return ans;
    }
};
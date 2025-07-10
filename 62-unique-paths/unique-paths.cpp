class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>=m || j>=n || i<0 || j<0){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int opt1=fun(i+1,j,m,n,dp);
        int opt2=fun(i,j+1,m,n,dp);
        return dp[i][j]=opt1+opt2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=fun(0,0,m,n,dp);
        return ans;
    }
};
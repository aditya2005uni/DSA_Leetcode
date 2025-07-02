// class Solution {
// public:
//     int fun(string text1, string text2,int m,int n,vector<vector<int>>&dp){
//         if(m<0 || n<0){
//             return 0;
//         }
//         if(dp[m][n]!=-1){
//             return dp[m][n];
//         }
//         if(text1[m]==text2[n]){
//             return dp[m][n]=1+fun(text1,text2,m-1,n-1,dp);
//         }
//         else{
//             return dp[m][n]=max(fun(text1,text2,m-1,n,dp),fun(text1,text2,m,n-1,dp));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size()-1;
//         int n=text2.size()-1;
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         int ans=fun(text1,text2,m,n,dp);
//         return ans;
//     }
// };
























class Solution {
    private:
    int fun(string &text1, string &text2,int m,int n,vector<vector<int>>&dp){
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(text1[m]==text2[n]){
            return dp[m][n]=1+fun(text1,text2,m-1,n-1,dp);
        }
        else{
            return dp[m][n]= max(fun(text1,text2,m,n-1,dp),fun(text1,text2,m-1,n,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length()-1;
        int n=text2.length()-1;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=fun(text1,text2,m,n,dp);
        return ans;
    }
};


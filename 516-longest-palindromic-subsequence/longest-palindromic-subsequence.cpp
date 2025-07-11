class Solution {
public:
    int fun(string &s1,string &s2,int m,int n,vector<vector<int>>&dp){
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s1[m]==s2[n]){
            return dp[m][n]=1+fun(s1,s2,m-1,n-1,dp);
        }
        else{
            return dp[m][n]=max(fun(s1,s2,m-1,n,dp),fun(s1,s2,m,n-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int m=s1.size()-1;
        int n=s2.size()-1;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return fun(s1,s2,m,n,dp);
    }
};









// class Solution {
//     public:
//     int fun(string &s1,string &s2,int m,int n,vector<vector<int>>&dp){
//         if(m<0 || n<0){
//             return 0;
//         }
//         if(dp[m][n]!=-1){
//             return dp[m][n];
//         }
//         if(s1[m]==s2[n]){
//             return dp[m][n]= 1+fun(s1,s2,m-1,n-1,dp);
//         }
//         else{
//             return dp[m][n]=max(fun(s1,s2,m-1,n,dp),fun(s1,s2,m,n-1,dp));
//         }
//     }
// public:
//     int longestPalindromeSubseq(string s) {
//         string s1=s;
//         int m=s1.size()-1;
//         int n=s.size()-1;
//         reverse(s.begin(),s.end());
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         int ans=fun(s,s1,m,n,dp);
//         return ans;
//     }
// };

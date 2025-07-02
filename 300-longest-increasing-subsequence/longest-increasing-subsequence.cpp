class Solution {
public:
    int fun(vector<int>& nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        int opt1=0;
        if(prev==-1 || nums[prev]<nums[curr]){
            opt1=1+fun(nums,curr,curr+1,dp);
        }
        int opt2=fun(nums,prev,curr+1,dp);
        return dp[prev+1][curr]=max(opt1,opt2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int p=-1;
        int c=0;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=fun(nums,p,c,dp);
        return ans;
    }
};











































//class Solution {
//     private:
//     int fun(vector<int>& nums,int p,int c,vector<vector<int>>&dp){
//         if(c>=nums.size()){
//             return 0;
//         }
//         if(dp[c][p+1]!=-1){
//             return dp[c][p+1];
//         }
//         int opt1=0;
//         if(p==-1 || (nums[p]<nums[c])){
//             opt1=1+fun(nums,c,c+1,dp);
//         }
//         int opt2=fun(nums,p,c+1,dp);
//         return dp[c][p+1]=max(opt1,opt2);
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         int ans=fun(nums,-1,0,dp);
//         return ans;
//     }
// };
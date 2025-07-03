class Solution {
    int fun(vector<int>& nums,int n,vector<int>&dp){
        if(n==0){
            return nums[n];
        }
        if(n==1){
            return max(nums[0],nums[n]);
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a=fun(nums,n-2,dp)+nums[n];
        int b=fun(nums,n-1,dp);
        return dp[n]=max(a,b);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        return fun(nums,n,dp);
    }
};





































//class Solution {
//     private:
//     int fun(vector<int>& nums,int n,vector<int>&dp){
//         if(n==0){
//             return nums[n];
//         }
//         if(n==1){
//             return max(nums[0],nums[1]);
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         int a=fun(nums,n-2,dp)+nums[n];
//         int b=fun(nums,n-1,dp);
//         return dp[n]=max(a,b);
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);
//         return fun(nums,n-1,dp);
//     }
// };

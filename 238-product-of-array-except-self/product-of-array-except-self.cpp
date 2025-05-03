class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=1;
        suf[n-1]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*suf[i];
        }
        return ans;

    }
};



































//class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>v1(n);
//         vector<int>v2(n);
//         v1[0]=1;
//         v2[n-1]=1;
//         for(int i=1;i<n;i++){
//             v1[i]=v1[i-1]*nums[i-1];
//         }
//         for(int i=n-2;i>=0;i--){
//             v2[i]=v2[i+1]*nums[i+1];
//         }
//         vector<int>ans(n);
//         for(int i=0;i<n;i++){
//             ans[i]=v1[i]*v2[i];
//         }
//         return ans;

//     }
// };
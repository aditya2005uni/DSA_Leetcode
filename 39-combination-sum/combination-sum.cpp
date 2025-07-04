class Solution {
    public:
    void fun(vector<int>& candidates, int tar,vector<vector<int>>&ans,vector<int>&out,int i){
        if(tar==0){
            ans.push_back(out);
            return;
        }
        if(tar<0){
            return;
        }
        if(i>=candidates.size()){
            return;
        }
        out.push_back(candidates[i]);
        fun(candidates,tar-candidates[i],ans,out,i);
        out.pop_back();
        fun(candidates,tar,ans,out,i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>out;
        fun(candidates,target,ans,out,0);
        return ans;
    }
};



























//class Solution {
//     private:
//     void fun(vector<vector<int>>&ans,vector<int>&out,int tar,vector<int>& candidates,int i){
//         if(tar==0){
//             ans.push_back(out);
//             return;
//         }
//         if(i>=candidates.size()){
//             return;
//         }
//         if(tar<0){
//             return;
//         }
//         out.push_back(candidates[i]);
//         fun(ans,out,tar-candidates[i],candidates,i);
//         out.pop_back();
//         fun(ans,out,tar,candidates,i+1);
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>>ans;
//         vector<int>out;
//         int n=candidates.size();
//         int i=0;
//         fun(ans,out,target,candidates,i);
//         return ans;
//     }
// };

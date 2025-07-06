class Solution {
    void fun(vector<int>& candidates, int tar,int i,vector<vector<int>>&ans,vector<int>&out){
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
        fun(candidates,tar-candidates[i],i,ans,out);
        out.pop_back();
        fun(candidates,tar,i+1,ans,out);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>out;
        fun(candidates,target,0,ans,out);
        return ans;
    }
};
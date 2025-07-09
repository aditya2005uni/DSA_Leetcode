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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>out;
        fun(candidates,target,ans,out,0);
        return ans;
    }
};
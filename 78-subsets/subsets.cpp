class Solution {
    void fun(vector<int>& nums,vector<vector<int>>&ans,vector<int>&out,int i){
        if(i>=nums.size()){
            ans.push_back(out);
            return;
        }
        out.push_back(nums[i]);
        fun(nums,ans,out,i+1);
        out.pop_back();
        fun(nums,ans,out,i+1);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>out;
        fun(nums,ans,out,0);
        return ans;
    }
};
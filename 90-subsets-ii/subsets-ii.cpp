class Solution {
    private:
    void fun(vector<vector<int>>&ans,vector<int>out,int i,vector<int>nums){
        if(i>=nums.size()){
            ans.push_back(out);
            return;
        }
        fun(ans,out,i+1,nums);
        int temp=nums[i];
        out.push_back(temp);
        fun(ans,out,i+1,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>out;
        int i=0;
        fun(ans,out,i,nums);
        sort(ans.begin(), ans.end());
        vector<vector<int>>ans2;
        if(ans.size()!=0){
            ans2.push_back(ans[0]);
        }
        
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=ans[i-1]){
                ans2.push_back(ans[i]);
            }
        }
        return ans2;
    }
};
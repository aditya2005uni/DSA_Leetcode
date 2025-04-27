class Solution {
    public:
    void fun(vector<int>& nums, int k,int &res,map<int,int>&mp,int ind){
        if(ind>=nums.size()){
            res++;
            return;
        }
        fun(nums,k,res,mp,ind+1);//not take
        if(!mp[nums[ind]+k] && !mp[nums[ind]-k]){
            mp[nums[ind]]++;
            fun(nums,k,res,mp,ind+1);//take
            mp[nums[ind]]--;
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int res=0;
        map<int,int>mp;
        fun(nums,k,res,mp,0);
        return res-1;
    }
};
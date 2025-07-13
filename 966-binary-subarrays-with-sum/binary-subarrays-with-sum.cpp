class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(mp.find(sum-goal)!=mp.end()){
                cnt=cnt+mp[sum-goal];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
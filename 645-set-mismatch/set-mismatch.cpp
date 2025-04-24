class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<int>ans;
        for(auto v:mp){
            if(v.second==2){
                ans.push_back(v.first);
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(mp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
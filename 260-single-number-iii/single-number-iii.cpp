class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto m:mp){
            if(m.second==1){
                ans.push_back(m.first);
            }
        }
        //sort(ans.begin(),ans.end());
        return ans;
    }
};
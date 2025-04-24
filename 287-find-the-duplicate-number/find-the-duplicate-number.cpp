class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto m:mp){
            if(m.second>=2){
                return m.first;
            }
        }
        return 0;
    }
};
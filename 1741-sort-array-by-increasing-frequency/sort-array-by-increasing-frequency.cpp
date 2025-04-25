class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        pair<int,int>p;
        vector<int>ans;
        vector<pair<int,int>>out;
        for(auto j:mp){
            out.push_back({j.second,j.first});
        }
        sort(out.begin(),out.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            else{
                return a.first<b.first;
            }
        });
        for(auto k:out){
            while(k.first){
                ans.push_back(k.second);
                k.first--;
            }
        }
        return ans;
    }
};
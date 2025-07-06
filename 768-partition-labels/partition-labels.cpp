class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int>ans;
        int size=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            size++;
            end=max(end,mp[s[i]]);
            if(end==i){
                ans.push_back(size);
                size=0;
            }
        }
        return ans;
    }
};
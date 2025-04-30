class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>mp;
        set<char>st;
        for(int i=0;i<jewels.size();i++){
            st.insert(jewels[i]);
        }
        for(auto i:stones){
            if(st.find(i)!=st.end()){
                mp[i]++;
            }
        }
        int cnt=0;
        for(auto j:mp){
            cnt=cnt+j.second;
        }
        return cnt;
    }
};
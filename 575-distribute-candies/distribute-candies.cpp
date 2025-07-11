class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int>mp;
        int n=candyType.size();
        for(int i=0;i<n;i++){
            mp[candyType[i]]++;
        }
        int m=mp.size();
        if(m<=n/2){
            return m;
        }
        return n/2;
    }
};
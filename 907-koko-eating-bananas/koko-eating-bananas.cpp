class Solution {
    public:
    bool isfun(int mid,vector<int>& piles, int h){
        int time=0;
        for(auto i:piles){
            time=time+i/mid;
            if(i%mid!=0){
            time++;
            }
        }
        if(time<=h){
            return true;
        }
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(isfun(mid,piles,h)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
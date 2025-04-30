class Solution {
    int fun(int n){
        if(n<=0){
            return 0;
        }
        int ans=1+fun(n/10);
        return ans;
    }
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto i:nums){
            int ans=fun(i);
            if(ans%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};
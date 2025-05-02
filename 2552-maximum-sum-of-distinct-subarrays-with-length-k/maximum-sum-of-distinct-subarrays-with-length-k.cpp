class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        set<int>st;
        int i=0;
        int j=0;
        long long sum=0;
        long long maxi=0;
        while(j<n){
            while(st.find(nums[j])!=st.end()){
                sum=sum-nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum=sum+nums[j];
            st.insert(nums[j]);
            if(j-i+1==k){
                maxi=max(maxi,sum);
                sum=sum-nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxi;
    }
};
class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<n;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        int cnt=0;
        int ans=-1;
        for(int k:mp.keySet()){
            if(mp.get(k)>cnt){
                cnt=mp.get(k);
                ans=k;
            }
        }
        return ans;
    }
}
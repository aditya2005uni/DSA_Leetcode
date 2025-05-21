class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int n=arrays.get(0).size();
        int mini=arrays.get(0).get(0);
        int maxi=arrays.get(0).get(n-1);
        int res=0;
        
        for(int i=1;i<arrays.size();i++){
            int m=arrays.get(i).size();
            int cumax=arrays.get(i).get(m-1);
            int cumin=arrays.get(i).get(0);

            res=Math.max(res, Math.abs(mini-cumax));
            res=Math.max(res, Math.abs(maxi-cumin));

            mini=Math.min(mini,cumin);
            maxi=Math.max(maxi,cumax);
        }
        return res;
    }
}


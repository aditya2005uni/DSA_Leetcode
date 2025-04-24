class Solution {
    void fun(vector<int>& cookies,vector<int>&v,int ind,int &res,int k){
        if(ind>=cookies.size()){
            int maxi=*max_element(v.begin(),v.end());
            res=min(res,maxi);
            return;
        }
        int c=cookies[ind];
        for(int i=0;i<k;i++){
            v[i]=v[i]+c;
            fun(cookies,v,ind+1,res,k);
            v[i]=v[i]-c;
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>v(k,0);
        int res=INT_MAX;
        fun(cookies,v,0,res,k);
        return res;
    }
};
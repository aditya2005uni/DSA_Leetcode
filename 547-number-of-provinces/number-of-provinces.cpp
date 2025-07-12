class Solution {
public:
    int find(int i,vector<int>&par){
        if(i==par[i]){
            return i;
        }
        return par[i]=find(par[i],par);
    }
    bool uni(int x,int y,vector<int>&par,vector<int>&rank){
        int px=find(x,par);
        int py=find(y,par);
        if(px==py){
            return false;
        }
        if(rank[px]>rank[py]){
            par[py]=px;
        }
        else if(rank[px]<rank[py]){
            par[px]=py;
        }
        else{
            par[px]=py;
            rank[py]++;
        }
        return true;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>par(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int cnt=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    if(uni(i,j,par,rank)){
                        cnt--;
                    }
                }
            }
        }
        return cnt;
    }
};
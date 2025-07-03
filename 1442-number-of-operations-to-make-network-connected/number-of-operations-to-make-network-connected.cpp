class Solution {
    public:
    int find(int i,vector<int>&par){
        if(i==par[i]){
            return i;
        }
        return par[i]=find(par[i],par);
    }
    void uni(int x,int y,vector<int>&par,vector<int>&rank){
        int px=find(x,par);
        int py=find(y,par);
        if(px==py){
            return;
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
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>par(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        if(connections.size()<n-1){
            return -1;
        }
        int cnt=n;

        for(auto i:connections){
            int a=i[0];
            int b=i[1];
            if(find(a,par)!=find(b,par)){
                uni(a,b,par,rank);
                cnt--;
            }
        }
        return cnt-1;
    }
};














































// class Solution {
//     private:
//     int find(int i,vector<int>&par){
//         if(i==par[i]){
//             return i;
//         }
//         return par[i]=find(par[i],par);
//     }
//     void uni(int x,int y,vector<int>&par,vector<int>&rank){
//         int px=find(x,par);
//         int py=find(y,par);
//         if(px==py){
//             return;
//         }
//         if(rank[px]>rank[py]){
//             par[py]=px;
//         }
//         else if(rank[px]<rank[py]){
//             par[px]=py;
//         }
//         else{
//             par[px]=py;
//             rank[py]++;
//         }
//     }
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         vector<int>rank(n,0);
//         vector<int>par(n);
//         for(int i=0;i<n;i++){
//             par[i]=i;
//         }
//         if(connections.size()<n-1){
//             return -1;
//         }
//         int count=n;
//         for(auto i:connections){
//             int a=i[0];
//             int b=i[1];
//             if(find(a,par)!=find(b,par)){
//                 uni(a,b,par,rank);
//                 count--;
//             }    
//         }
//         return count-1;
//     }
// };

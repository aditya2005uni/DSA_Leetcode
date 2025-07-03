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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>par(n+1);
        vector<int>rank(n+1,0);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
        vector<int>ans;
        for(auto i:edges){
            int a=i[0];
            int b=i[1];
            if(find(a,par)==find(b,par)){
                ans.push_back(a);
                ans.push_back(b);
            }
            else{
                uni(a,b,par,rank);
            }
        }
        return ans;
    }
};
































//class Solution {
//     int find(int x,vector<int>&par){
//         if(x==par[x]){
//             return x;
//         }
//         return par[x]=find(par[x],par);
//     }
//     void uni(int x,int y,vector<int>& par, vector<int>& rank){
//         int px = find(x, par);
//         int py = find(y, par);
//         if(px==py){
//             return;
//         }
//         if (rank[px] > rank[py]) {
//             par[py] = px;
//         } 
//         else if (rank[py] > rank[px]) {
//             par[px] = py;
//         } 
//         else {
//             par[px] = py;
//             rank[py]++;
//         }
//     }
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n=edges.size();
//         vector<int>par(n+1);
//         vector<int>rank(n+1,0);
//         for(int i=0;i<=n;i++){
//             par[i]=i;
//         }
//         for(auto v:edges){
//             int a=v[0];
//             int b=v[1];
//             if(find(a,par)==find(b,par)){
//                 return v;
//             }
//             else{
//                 uni(a,b,par,rank);
//             }
//         }
//         return {};
//     }
// };
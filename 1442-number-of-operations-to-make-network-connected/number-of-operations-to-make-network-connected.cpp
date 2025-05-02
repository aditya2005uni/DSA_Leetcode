class Solution {
    public:
    int find(int i, vector<int>&par){
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
        vector<int>rank(n,0);
        vector<int>par(n);
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
























// class Solution {
// public:
//     int find(int x, vector<int>& par) {
//         if (x == par[x]) {
//             return x;
//         }
//         return par[x] = find(par[x], par);
//     }

//     void uni(int x, int y, vector<int>& par, vector<int>& rank) {
//         int px = find(x, par);
//         int py = find(y, par);
//         if (px == py) {
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

//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if (connections.size() < n - 1) {
//             return -1;
//         }

//         vector<int> par(n);
//         vector<int> rank(n, 0);

//         for (int i = 0; i < n; i++) {
//             par[i] = i;
//         }

//         int comp = n; // Number of components
//         for (auto& v : connections) {
//             if (find(v[0], par) != find(v[1], par)) {
//                 uni(v[0], v[1], par, rank);
//                 comp--;
//             }
//         }

//         return comp - 1;
//     }
// };


















// class Solution {
//     public:
//     vector<int>par;
//     vector<int>rank;
//     int find(int x){
//         if(x==par[x]){
//             return x;
//         }
//         return par[x]=find(par[x]);
//     }
//     void uni(int x,int y){
//         int px=find(x);
//         int py=find(y);
//         if(px==py){
//             return;
//         }
//         if(rank[px]>rank[py]){
//             par[py]=px;
//         }
//         else if(rank[py]>rank[px]){
//             par[px]=py;
//         }
//         else{
//             par[px]=py;
//             rank[py]++;
//         }
//         return;
//     }
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         if(connections.size()<n-1){
//             return -1;
//         }
//         par.resize(n);
//         rank.resize(n,0);
//         for(int i=0;i<n;i++){
//             par[i]=i;
//         }
//         int comp=n;//componets
//         for(auto v:connections){
//             if(find(v[0])!=find(v[1])){
//                 uni(v[0],v[1]);
//                 comp--;
//             }
//         }
//         return comp-1;
//     }
// };
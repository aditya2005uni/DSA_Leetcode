class Solution {
    private:
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n,int &cal){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return;
        }
        cal++;
        grid[i][j]=0;
        dfs(grid,i+1,j,m,n,cal);
        dfs(grid,i-1,j,m,n,cal);
        dfs(grid,i,j+1,m,n,cal);
        dfs(grid,i,j-1,m,n,cal);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int cal=0;
                    dfs(grid,i,j,m,n,cal);
                    area=max(area,cal);
                }
            }
        }
        return area;
    }
};






























// class Solution {
//     private:
//     void dfs(vector<vector<int>>&grid,int i,int j,int m,int n,int &c){
//         if(i>=m || i<0 || j>=n || j<0 || grid[i][j]==0){
//             return;
//         }
//         c++;
//         grid[i][j]=0;
//         dfs(grid,i+1,j,m,n,c);
//         dfs(grid,i-1,j,m,n,c);
//         dfs(grid,i,j+1,m,n,c);
//         dfs(grid,i,j-1,m,n,c);
//     }
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int ans=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     int c=0;
//                     dfs(grid,i,j,m,n,c);
//                     ans=max(ans,c);
//                 }
//             }
//         }
//         return ans;
//     }
// };



























//class Solution {
//     private:
//     void dfs(int i,int j,vector<vector<int>>& grid,int &maxi,int m,int n){
//         if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
//             return;
//         }
//         maxi++;
//         grid[i][j]=0;
//         dfs(i+1,j,grid,maxi,m,n);
//         dfs(i-1,j,grid,maxi,m,n);
//         dfs(i,j+1,grid,maxi,m,n);
//         dfs(i,j-1,grid,maxi,m,n);
//         return;
//     }
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int ans=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     int maxi=0;
//                     dfs(i,j,grid,maxi,m,n);
//                     ans=max(ans,maxi);
//                 }
//             }
//         }
//         return ans;
//     }
// };
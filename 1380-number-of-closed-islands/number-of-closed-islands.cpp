class Solution {
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1){
            return;
        }
        grid[i][j]=1;
        dfs(grid,i+1,j,m,n);
        dfs(grid,i-1,j,m,n);
        dfs(grid,i,j+1,m,n);
        dfs(grid,i,j-1,m,n);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int row=0;row<m;row++){
            if(grid[row][0]==0){
                dfs(grid,row,0,m,n);
            }
            if(grid[row][n-1]==0){
                dfs(grid,row,n-1,m,n);
            }
        }
        for(int col=0;col<n;col++){
            if(grid[0][col]==0){
                dfs(grid,0,col,m,n);
            }
            if(grid[m-1][col]==0){
                dfs(grid,m-1,col,m,n);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;

    }
};



























//class Solution {
//     private:
//     void dfs(int i, int j,int m,int n,vector<vector<int>>& grid){
//         if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1){
//             return;
//         }
//         grid[i][j]=1;
//         dfs(i+1,j,m,n,grid);
//         dfs(i-1,j,m,n,grid);
//         dfs(i,j+1,m,n,grid);
//         dfs(i,j-1,m,n,grid);
//         return;
//     }
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         for(int row=0;row<m;row++){
//             if(grid[row][0]==0){
//                 dfs(row,0,m,n,grid);
//             }
//             if(grid[row][n-1]==0){
//                 dfs(row,n-1,m,n,grid);
//             }
//         }
//         for(int col=0;col<n;col++){
//             if(grid[0][col]==0){
//                 dfs(0,col,m,n,grid);
//             }
//             if(grid[m-1][col]==0){
//                 dfs(m-1,col,m,n,grid);
//             }
//         }
//         int count=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==0){
//                     dfs(i,j,m,n,grid);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
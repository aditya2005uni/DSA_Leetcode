class Solution {
    void fun(vector<vector<int>>& heights,int i,int j,int m,int n,int prev,vector<vector<int>>&oc){
        if(i<0 || i>=m ||j<0 ||j>=n || prev>heights[i][j] || oc[i][j]==1){
            return;
        }
        oc[i][j]=1;
        fun(heights,i+1,j,m,n,heights[i][j],oc);
        fun(heights,i-1,j,m,n,heights[i][j],oc);
        fun(heights,i,j+1,m,n,heights[i][j],oc);
        fun(heights,i,j-1,m,n,heights[i][j],oc);

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>pac(m,vector<int>(n,0));
        vector<vector<int>>atl(m,vector<int>(n,0));
        vector<vector<int>>ans;
        for(int row=0;row<m;row++){
            fun(heights,row,0,m,n,-1,pac);
            fun(heights,row,n-1,m,n,-1,atl);
        }
        for(int col=0;col<n;col++){
            fun(heights,0,col,m,n,-1,pac);
            fun(heights,m-1,col,m,n,-1,atl);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    vector<int>out(2);
                    out[0]=i;
                    out[1]=j;
                    ans.push_back(out);
                }
            }
        }
        return ans;
    }
};

























//class Solution {
// public:
//     void fun(vector<vector<int>>& heights,int i,int j,int prev,int m,int n,vector<vector<int>>&oc){
//         if(i<0 || i>=m || j<0 || j>=n || heights[i][j]<prev || oc[i][j]==1){
//             return;
//         }
//         oc[i][j]=1;
//         fun(heights,i+1,j,heights[i][j],m,n,oc);
//         fun(heights,i-1,j,heights[i][j],m,n,oc);
//         fun(heights,i,j+1,heights[i][j],m,n,oc);
//         fun(heights,i,j-1,heights[i][j],m,n,oc);
//     }
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int m=heights.size();
//         int n=heights[0].size();
//         vector<vector<int>>pac(m,vector<int>(n,0));
//         vector<vector<int>>atl(m,vector<int>(n,0));
//         vector<vector<int>>ans;
//         for(int row=0;row<m;row++){
//             fun(heights,row,0,-1,m,n,pac);
//             fun(heights,row,n-1,-1,m,n,atl);
//         }
//         for(int col=0;col<n;col++){
//             fun(heights,0,col,-1,m,n,pac);
//             fun(heights,m-1,col,-1,m,n,atl);
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(pac[i][j]==1&&atl[i][j]==1){
//                     vector<int>aa(2);
//                     aa[0]=i;
//                     aa[1]=j;
//                     ans.push_back(aa);
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int m,int n,int &color,int &ocolor){
        if(i>=m || i<0 || j>=n || j<0 || image[i][j]!=ocolor){
            return;
        }
        image[i][j]=color;
        dfs(image,i+1,j,m,n,color,ocolor);
        dfs(image,i,j+1,m,n,color,ocolor);
        dfs(image,i-1,j,m,n,color,ocolor);
        dfs(image,i,j-1,m,n,color,ocolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int ocolor=image[sr][sc];
        if(ocolor!=color){
            dfs(image,sr,sc,m,n,color,ocolor);
        }
        return image;
    }
};
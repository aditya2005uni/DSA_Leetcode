class Solution {
    public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O'){
            return;
        }
        board[i][j]='N';
        dfs(i+1,j,m,n,board);
        dfs(i-1,j,m,n,board);
        dfs(i,j+1,m,n,board);
        dfs(i,j-1,m,n,board);
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int col=0;col<n;col++){
            if(board[0][col]=='O'){
                dfs(0,col,m,n,board);
            }
            if(board[m-1][col]=='O'){
                dfs(m-1,col,m,n,board);
            }
        }
        for(int row=0;row<m;row++){
            if(board[row][0]=='O'){
                dfs(row,0,m,n,board);
            }
            if(board[row][n-1]=='O'){
                dfs(row,n-1,m,n,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='N'){
                    board[i][j]='O';
                }
            }
        }
    }
};
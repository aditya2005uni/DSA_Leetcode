class Solution {
    bool dfs(int i,int j,int m,int n,vector<vector<char>>& board, string word,int ind){
        if(ind==word.size()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n|| ind>=word.size() || board[i][j]!=word[ind]||board[i][j]=='*'){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='*';
        bool a=dfs(i+1,j,m,n,board,word,ind+1);
        bool b=dfs(i-1,j,m,n,board,word,ind+1);
        bool c=dfs(i,j+1,m,n,board,word,ind+1);
        bool d=dfs(i,j-1,m,n,board,word,ind+1);
        board[i][j]=temp;
        return a||b||c||d;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,m,n,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};





























// class Solution {
//     private:
//     bool find(vector<vector<char>>& board, int i, int j,int m,int n,int ind, string& word){
//         if(ind==word.size()){
//             return true;
//         }
//         if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[ind]){
//             return false;
//         }
//         char temp=board[i][j];
//         board[i][j]='#';
//         bool found=find(board,i+1,j,m,n,ind+1,word)||find(board,i-1,j,m,n,ind+1,word)||
//                     find(board,i,j+1,m,n,ind+1,word)||find(board,i,j-1,m,n,ind+1,word);
//         board[i][j]=temp;
//         return found;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m=board.size();
//         int n=board[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j]==word[0] && find(board,i,j,m,n,0,word)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
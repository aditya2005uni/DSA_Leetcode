// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         if(trust.size()==n){
//             return -1;
//         }
//         vector<int>vis(n+1,0);
//         for(auto i:trust){
//             vis[i[0]]=1;
//         }
//         for(int i=1;i<=n;i++){
//             if(vis[i]==0){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

































class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>data(n+1,0);
        for(auto i:trust){
            data[i[0]]--;
            data[i[1]]++;
        }
        for(int i=1;i<=n;i++){
            int x=data[i];
            if(x==n-1){
                return i;
            }
        }
        return -1;
    }
};
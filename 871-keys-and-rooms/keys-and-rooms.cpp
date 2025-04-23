class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto i:rooms[f]){
                if(vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};




























// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n=rooms.size();
//         vector<int>vis(n,0);
//         queue<int>q;
//         q.push(0);
//         vis[0]=1;
//         while(!q.empty()){
//             int f=q.front();
//             q.pop();
//             for(auto i:rooms[f]){
//                 if(vis[i]==0){
//                     vis[i]=1;
//                     q.push(i);
//                 }
//             }
//         }
//         for(auto x:vis){
//             if(x==0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };



























//class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n=rooms.size();
//         vector<int>vis(n,0);
//         queue<int>q;
//         q.push(0);
//         vis[0]=1;
//         while(!q.empty()){
//             int f=q.front();
//             q.pop();
//             for(auto x:rooms[f]){
//                 if(vis[x]==0){
//                     vis[x]=1;
//                     q.push(x);
//                 }
//             }
//         }
//         for(auto i:vis){
//             if(i==0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto j:mp){
            pq.push(make_pair(j.second,j.first));
        }
        vector<int>ans;
        while(k){
            pair<int,int>temp=pq.top();
            ans.push_back(temp.second);
            pq.pop();
            k--;
        }
        return ans;
    }
};

















// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int,int>mp;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }
//         priority_queue<pair<int,int>>pq;
//         for(auto i:mp){
//             pq.push(make_pair(i.second,i.first));
//         }
//         vector<int>ans;
//         while(k){
//             pair<int,int>temp=pq.top();
//             pq.pop();
//             ans.push_back(temp.second);
//             k--;
//         }
//         return ans;
//     }
// };




















// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int,int>mp;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         for(auto i:mp){
//             pq.push(make_pair(i.second,i.first));
//             if(pq.size()>k){
//                 pq.pop();
//             }
//         }
//         vector<int>ans;
//         while(!pq.empty()){
//             pair<int,int>temp=pq.top();
//             pq.pop();
//             ans.push_back(temp.second);
//         }
//         return ans;
//     }
// };



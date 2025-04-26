/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans;
        queue<TreeNode*>q;
        q.push(root);
    
        while(!q.empty()){
            int size=q.size();
            long long sum=0;

            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                sum=sum+temp->val;
            
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
            ans.push_back(sum);
        }
        if (k >ans.size()) return -1;
        
        sort(ans.begin(),ans.end());
        return ans[ans.size()-k];
    }
};































////////////TLE/////////////////////
//class Solution {
//     private:
//     void fun(TreeNode* root,map<int,long long>&mp,int lev){
//         if(root==nullptr){
//             return;
//         }
//         mp[lev]=mp[lev]+root->val;
//         fun(root->left,mp,lev+1);
//         fun(root->right,mp,lev+1);
//     }
// public:
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         map<int,long long>mp;
//         int lev=0;
//         fun(root,mp,lev);
//         priority_queue<long long>pq;
//         for(auto i:mp){
//             pq.push(i.second);
//         }
//         if(pq.size()<k){
//             return -1;
//         }
//         long long ans=0;
//         while(k){
//             ans=pq.top();
//             pq.pop();
//             k--;
//         }
//         return ans;
//     }
// };
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>lev;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                lev.push_back(node->val);
            }
            ans.push_back(lev);
        }
        return ans;
    }
};






























// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         queue<TreeNode*>q;
//         if(root==nullptr){
//             return ans;
//         }
//         q.push(root);
//         while(1){
//             int size=q.size();
//             if(size==0){
//                 return ans;
//             }
//             vector<int>data;
//             while(size>0){
//                 TreeNode*temp=q.front();
//                 q.pop();
//                 data.push_back(temp->val);
//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//                 size--;
//             }
//             ans.push_back(data);
//         }
//         return ans;
//     }
// };

































// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         queue<TreeNode*>q;
//         q.push(root);
//         if(root==nullptr){
//             return ans;
//         }
//         while(1){
//             int size=q.size();
//             if(size==0){
//                 return ans;
//             }
//             vector<int>data;
//             while(size>0){
//                 TreeNode*temp=q.front();
//                 q.pop();
//                 data.push_back(temp->val);
//                 if(temp->left!=nullptr){
//                     q.push(temp->left);
//                 }
//                 if(temp->right!=nullptr){
//                     q.push(temp->right);
//                 }
//                 size--;
//             }
//             ans.push_back(data);
//         }
//         return ans;
//     }
// };


























// class Solution {
//     private:
//     void fun(TreeNode* root,map<int,vector<int>>&mp,int lev){
//         if(root==nullptr){
//             return ;
//         }
//         mp[lev].push_back(root->val);
//         fun(root->left,mp,lev+1);
//         fun(root->right,mp,lev+1);
//     }
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         map<int,vector<int>>mp;
//         int lev;
//         fun(root,mp,lev);
//         vector<vector<int>>ans;
//         for(auto i:mp){
//             ans.push_back(i.second);
//         }
//         return ans;
//     }
// };
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
// class Solution {
//     private:
//     void res(TreeNode* root, int k,int &i,int &j){
//         if(root==nullptr){
//             return ;
//         }
//         res(root->left,k,i,j);
//         if(i==k){
//             j=root->val;
//         }
//         i++;
//         res(root->right,k,i,j);
//         return;
//     }
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         int i=1;
//         int j=0;
//         res(root,k,i,j);
//         return j;
//     }
// };













class Solution {
    private:
    void res(TreeNode* root,vector<int>&ans){
        if(root==nullptr){
            return;
        }
        res(root->left,ans);
        ans.push_back(root->val);
        res(root->right,ans);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        res(root,ans);
        return ans[k-1];
    }
};
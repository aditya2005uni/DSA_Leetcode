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
    void fun(TreeNode* root,int maxi,int &cnt){
        if(root==nullptr){
            return;
        }
        if(root->val>=maxi){
            maxi=max(maxi,root->val);
            cnt++;
        }
        fun(root->left,maxi,cnt);
        fun(root->right,maxi,cnt);
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt=0;
        fun(root,root->val,cnt);
        return cnt;
    }
};
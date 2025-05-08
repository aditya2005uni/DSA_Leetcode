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
    void fun(TreeNode*&root){
        if(root==nullptr){
            return;
        }
        fun(root->left);
        fun(root->right);
        if(root->val==0 && root->left==nullptr && root->right==nullptr){
            root=nullptr;
            return;
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        fun(root);
        return root;
    }
};
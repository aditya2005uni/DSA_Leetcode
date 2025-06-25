/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* fun(TreeNode* original, TreeNode* cloned, TreeNode* target,TreeNode*&res){
        if(original==nullptr){
            return nullptr;
        }
        if(original==target){
            res=cloned;
        }
        fun(original->left,cloned->left,target,res);
        fun(original->right,cloned->right,target,res);
        return res;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode*res=nullptr;
        return fun(original,cloned,target,res);
    }
};
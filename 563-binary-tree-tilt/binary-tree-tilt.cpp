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
    int fun(TreeNode* root,int &sum){
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            return root->val;
        }
        int l=fun(root->left,sum);
        int r=fun(root->right,sum);
        sum=sum+abs(l-r);
        return root->val+l+r;
    }
public:
    int findTilt(TreeNode* root) {
        int sum=0;
        fun(root,sum);
        return sum;
    }
};
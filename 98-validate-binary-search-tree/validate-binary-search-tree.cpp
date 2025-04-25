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
    bool fun(TreeNode* root,long long maxi,long long mini){
        if(root==nullptr){
            return true;
        }
        if(root->val>mini && root->val<maxi){
            bool l=fun(root->left,root->val,mini);
            bool r=fun(root->right,maxi,root->val);
            if(l&&r){
                return true;
            }
            
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        bool ans=fun(root,LLONG_MAX,LLONG_MIN);
        return ans;
    }
};
























//class Solution {
//     bool fun(TreeNode* root,long long maxi,long long mini){
//         if(root==nullptr){
//             return true;
//         }
//         if(root->val>mini && root->val<maxi){
//             bool l=fun(root->left,root->val,mini);
//             bool r=fun(root->right,maxi,root->val);
//             if(l&&r){
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         bool ans=fun(root,LLONG_MAX, LLONG_MIN);
//         return ans;
//     }
// };
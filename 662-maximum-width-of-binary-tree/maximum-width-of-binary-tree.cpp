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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll maxi=0;
        while(!q.empty()){
            ll l=q.front().second;
            ll r=q.back().second;
            maxi=max(maxi,r-l+1);
            int n=q.size();
            while(n--){
                TreeNode*curr=q.front().first;
                ll idx=q.front().second;
                q.pop();
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    q.push({curr->right,2*idx+2});
                }
            }
        }
        return maxi;
    }
};
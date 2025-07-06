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
    private:
    vector<TreeNode*>solve(int n){
        vector<TreeNode*>ans;
        if(n%2==0){
            return ans;
        }
        if(n==1){
            TreeNode* root=new TreeNode(0);
            ans.push_back(root);
            return ans;
        }
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>l=solve(i);
            vector<TreeNode*>r=solve(n-i-1);

            for(auto i:l){
                for(auto j:r){
                    TreeNode* root=new TreeNode(0);
                    root->left=i;
                    root->right=j;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);

    }
};
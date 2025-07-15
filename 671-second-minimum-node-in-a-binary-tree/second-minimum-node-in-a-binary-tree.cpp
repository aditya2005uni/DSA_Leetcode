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
    void fun(TreeNode* root,vector<int>&res){
        if(root==nullptr){
            return;
        }
        fun(root->left,res);
        res.push_back(root->val);
        fun(root->right,res);
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int>res;
        fun(root,res);
        // set<int>st;
        // for(auto i:res){
        //     st.insert(i);
        // }
        // vector<int>ans;
        // for(auto i:st){
        //     ans.push_back(i);
        // }
        // int n=ans.size();
        // if(n<2){
        //     return -1;
        // }
        // return ans[n-2];

        set<int> st(res.begin(), res.end()); 
        if (st.size() < 2) {
            return -1;
        }
        auto it = st.begin();
        ++it; 
        return *it;
    }
};
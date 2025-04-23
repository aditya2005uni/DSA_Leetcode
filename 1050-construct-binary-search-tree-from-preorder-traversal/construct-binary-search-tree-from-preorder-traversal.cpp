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
    int preind=0;
    TreeNode*fun(vector<int>& preorder, vector<int>& inorder,int is,int ie){
        if(is>ie){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[preind]);
        preind++;
        int ind;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root->val){
                ind=i;
                break;
            }
        }
        root->left=fun(preorder,inorder,is,ind-1);
        root->right=fun(preorder,inorder,ind+1,ie);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>inorder;
        inorder=preorder;
        sort(inorder.begin(),inorder.end());
        return fun(preorder,inorder,0,n-1);

    }
};
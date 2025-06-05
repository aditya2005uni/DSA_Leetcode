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
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder,int is,int ie,int &n){
        if(is>ie){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[n]);
        n--;
        int ind;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root->val){
                ind=i;
                break;
            }
        }
        root->right=fun(inorder,postorder,ind+1,ie,n);
        root->left=fun(inorder,postorder,is,ind-1,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size()-1;
        return fun(inorder,postorder,0,inorder.size()-1,n);
    }
};






















//class Solution {
//     private:
//     TreeNode* fun(vector<int>& inorder, vector<int>& postorder,int is,int ie,int &n){
//         if(is>ie){
//             return nullptr;
//         }
//         TreeNode* root=new TreeNode(postorder[n]);
//         n--;
//         int index;
//         for(int i=0;i<inorder.size();i++){
//             if(inorder[i]==root->val){
//                 index=i;
//                 break;
//             }
//         }
//         root->right=fun(inorder,postorder,index+1,ie,n);
//         root->left=fun(inorder,postorder,is,index-1,n);

//         return root;
//     }

// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n=postorder.size()-1;
//         return fun(inorder,postorder,0,inorder.size()-1,n);
//     }
// };
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root==nullptr){
//             return root;
//         }
//         if(root->val>key){
//             root->left=deleteNode(root->left,key);
//         }
//         else if(root->val<key){
//             root->right=deleteNode(root->right,key);
//         }
//         else{
//             if(root->left==nullptr && root->right==nullptr){
//                 delete root;
//                 return nullptr;
//             }
//             else if(root->left!=nullptr && root->right==nullptr){
//                 TreeNode* temp=root->right;
//                 delete root;
//                 return temp;
//             }
//             else if(root->left==nullptr && root->right!=nullptr){
//                 TreeNode* temp=root->leftt;
//                 delete root;
//                 return temp;
//             }
//             else{
//                 TreeNode* minn=minval
//             }
//         }
//     }
// };





























class Solution {
    private:
    TreeNode* minval(TreeNode* root){
        TreeNode* curr=root;
        while(curr&&curr->left!=nullptr){
            curr=curr->left;
        }
        return curr;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->right==nullptr&&root->left==nullptr){
                delete root;
                return nullptr;
            }
            else if(root->right!=nullptr&&root->left==nullptr){
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr&&root->left!=nullptr){
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }
            else{
                int minn=minval(root->right)->val;
                root->val=minn;
                root->right=deleteNode(root->right,minn);
                return root;
            }
        }
        return root;
    }
};
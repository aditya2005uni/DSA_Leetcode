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
    bool issame(TreeNode* p,TreeNode* q){
        if(p==nullptr && q==nullptr){
            return true;
        }
        if((p==nullptr && q!=nullptr) || (p!=nullptr && q==nullptr)){
            return false;
        }
        bool l=issame(p->left,q->left);
        bool r=issame(p->right,q->right);
        if(p->val==q->val && l && r){
            return true;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr){
            return true;
        }
        if(root==nullptr && subRoot!=nullptr){
            return false;
        }
        if(subRoot->val==root->val && issame(subRoot,root)){
            return true;
        }
        bool lr=isSubtree(root->left,subRoot);
        bool rr=isSubtree(root->right,subRoot);
        return (lr||rr);
    }
};
































//class Solution {
//     private:
//     bool sametree(TreeNode* p, TreeNode* q){
//         if(p==nullptr && q==nullptr){
//             return true;
//         }
//         if((p==nullptr && q!=nullptr) || (q==nullptr && p!=nullptr)){
//             return false;
//         }
//         bool a=sametree(p->left,q->left);
//         bool b=sametree(p->right,q->right);
//         if((p->val == q->val)&&a && b){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// public:
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(subRoot==nullptr){
//             return true;
//         }
//         if(root==nullptr && subRoot!=nullptr){
//             return false;
//         }
//         if(sametree(root,subRoot)){
//             return true;
//         }
//         bool c=isSubtree(root->left,subRoot);
//         bool d=isSubtree(root->right,subRoot);
//         if(c||d){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };
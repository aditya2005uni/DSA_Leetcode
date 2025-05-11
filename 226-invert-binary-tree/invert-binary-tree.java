/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode fun(TreeNode root){
        if(root==null){
            return null;
        }
        TreeNode l=fun(root.left);
        TreeNode r=fun(root.right);
        TreeNode temp=root.left;
        root.left=root.right;
        root.right=temp;
        return root;
    }
    public TreeNode invertTree(TreeNode root) {
        TreeNode ans=fun(root);
        return ans;
    }
}

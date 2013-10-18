
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void flatten(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root == null) return ;
        flattenHelper(root);
        
    }
    
    TreeNode flattenHelper(TreeNode root){
        TreeNode rightMost = null, rightOfLeft = null;
        if(root.left != null)
            rightOfLeft = flattenHelper(root.left);
        if(root.right != null)
            rightMost = flattenHelper(root.right);
        if(root.left != null && root.right != null){
            rightOfLeft.right = root.right;
            root.right = root.left;
            root.left = null;
            return rightMost;
        }
        if(root.left != null && root.right == null){
            root.right = root.left;
            root.left = null;
            return rightOfLeft;
        }
        if(root.left == null && root.right != null){
            return rightMost;
        }
        return root;
    }
}

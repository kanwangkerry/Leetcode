
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
    public int minDepth(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root == null)
            return 0;
        if(root.left == null && root.right == null)
            return 1;
        int left = 0, right = 0;
        if(root.left != null && root.right != null){
            left = minDepth(root.left);
            right = minDepth(root.right);
            return 1+ (left>right?right:left);
        }
        if(root.left != null)
            return 1+minDepth(root.left);
        if(root.right != null)
            return 1+minDepth(root.right);
        return 0;
    }
}

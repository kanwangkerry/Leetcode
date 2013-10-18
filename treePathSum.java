

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
    public int maxPathSum(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return updatePathSum(root);
    }
    
    int updatePathSum(TreeNode root){
        int left = 0, right = 0;
        int lmax = root.val, rmax = root.val;
        if(root.left != null){
            lmax = updatePathSum(root.left);
            left = root.left.val;
        }
        if(root.right != null){
            rmax = updatePathSum(root.right);
            right = root.right.val;
        }
        int max = root.val;
        if(right >0)
            max += right;
        if(left >0)
            max += left;
        if(max < lmax)
            max = lmax;
        if(max < rmax)
            max = rmax;
        if(left > 0 && right > 0){
            root.val = root.val + (left>right?left:right);
        }
        else if(left > 0 && right <=0){
            root.val += left;
        }
        else if(right >0 && left <=0){
            root.val += right;
        }
        return max;
    }
}

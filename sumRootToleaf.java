
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
    public int sumNumbers(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        TreeNode index;
        if(root == null) return 0;
        ArrayList<Integer> result = genNumber(root, 0);
        int sum = 0;
        for(int i = 0 ; i < result.size() ;i ++){
            sum += result.get(i).intValue();
        }
        return sum;
    }
    
    ArrayList<Integer> genNumber(TreeNode root, int pVal){
        ArrayList<Integer> left, right, result;
        result = new ArrayList<Integer>();
        if(root.left ==null && root.right == null){
            result.add(new Integer(pVal*10+root.val));
        }
        if(root.left != null){
            left = genNumber(root.left, pVal*10+root.val);
            result.addAll(left);
        }
        if(root.right != null){
            right = genNumber(root.right, pVal*10+root.val);
            result.addAll(right);
        }
        return result;
    }
}

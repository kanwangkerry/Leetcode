
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
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();

        ArrayList<ArrayList<Integer>> childResult;
        if(root == null) return result;
        if(root.left == null && root.right == null && root.val == sum){
            ArrayList<Integer> path;
            path = new ArrayList<Integer>();
            path.add(Integer.valueOf(root.val));
            result.add(path);
        }
        if(root.left != null){
            childResult = pathSum(root.left, sum - root.val);
            for(ArrayList<Integer> path: childResult){
                path.add(0, Integer.valueOf(root.val));
                result.add(path);
            }
        }
        if(root.right != null){
            childResult = pathSum(root.right, sum - root.val);
            for(ArrayList<Integer> path: childResult){
                path.add(0, Integer.valueOf(root.val));
                result.add(path);
            }
        }
        return result;
    }
}

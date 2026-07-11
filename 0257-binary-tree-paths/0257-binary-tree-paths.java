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

    // Stores all root-to-leaf paths
    public List<String> result = new ArrayList<>();

    public List<String> binaryTreePaths(TreeNode root) {
        helperFunc(new StringBuilder(), root);
        return result;
    }

    private void helperFunc(StringBuilder path, TreeNode root) {

        // Base case
        if (root == null) {
            return;
        }

        // Save the current length for backtracking
        int len = path.length();

        // Append separator if this is not the first node
        if (len != 0) {
            path.append("->");
        }

        // Append the current node's value
        path.append(root.val);

        // If it's a leaf node, store the path
        if (root.left == null && root.right == null) {
            result.add(path.toString());
        } else {
            // Explore left and right subtrees
            helperFunc(path, root.left);
            helperFunc(path, root.right);
        }

        // Backtrack to restore the previous path
        path.setLength(len);
    }
}
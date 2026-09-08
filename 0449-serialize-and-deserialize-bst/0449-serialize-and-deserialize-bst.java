/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return null;
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }
    public void serialize(TreeNode root, StringBuilder sb) {
        if (root == null) return;
        sb.append(root.val).append(",");
        serialize(root.left, sb);
        serialize(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null) return null;
        String[] d = data.split(",");
        int[] arr = new int[d.length];
        for (int i = 0; i < d.length; i++) {
            arr[i] = Integer.parseInt(d[i]);
        }
        return solve(0, arr.length - 1, arr);
    }
    public TreeNode solve(int start, int end, int[] arr) {
        if (start > end) return null;
        TreeNode root = new TreeNode(arr[start]);
        int i = start + 1;
        while (i <= end && arr[i] < root.val) {
            i++;
        }
        root.left = solve(start + 1, i - 1, arr);
        root.right = solve(i, end, arr);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
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
    private int pos = 0;
    private String[] nums;
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) 
            return "#,";
            
        String result = root.val + ",";
        result += serialize(root.left);
        result += serialize(root.right);
        return result;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        pos = 0;
        nums = data.split(",");
        return deserialize();
    }
    
    private TreeNode deserialize() {
        if (nums[pos].equals("#")) {
            pos++;
            return null;
        }
        
        TreeNode root = new TreeNode(Integer.parseInt(nums[pos]));
        pos++;
        root.left = deserialize();
        root.right = deserialize();
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
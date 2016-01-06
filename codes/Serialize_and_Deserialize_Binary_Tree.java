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
        if (root == null) return "#";
        String str = root.val + "";
        str += "," + serialize(root.left);
        str += "," + serialize(root.right);
        return str;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] datas = data.split(",");
        if (datas.length <= 1) return null;
        Deque<String> strList = new LinkedList<String>(Arrays.asList(datas));
        TreeNode root = deserialize(strList);
        return root;
    }

    private TreeNode deserialize(Deque<String> strList) {
        if (strList.size() == 0) return null;
        String str = strList.pop();
        if (str.equals("#")) return null;
        TreeNode root = new TreeNode(Integer.parseInt(str));
        root.left = deserialize(strList);
        root.right = deserialize(strList);
        return root;
    }
}

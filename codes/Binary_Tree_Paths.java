/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<String>();
        if (root == null) 
            return paths;
        String path = "";
        dfs(root, path, paths);
        return paths;
    }
    
    private void dfs(TreeNode root, String path, List<String> paths) {
        if (root == null)
            return;
        
        int val = root.val;
        if (!path.equals("")) 
            path += "->";
        path += val;
        
        if (root.left == null && root.right == null) 
            paths.add(path);
            
        if (root.left != null)
            dfs(root.left, path, paths);
        
        if (root.right != null)
            dfs(root.right, path, paths);
    }
}
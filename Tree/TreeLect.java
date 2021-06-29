import java.util.ArrayList;

public class TreeLect{
    public static class TreeNode{
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
        
        void TreeNode(int val){
            this.val = val;
        }
    }
    
    public static int size(TreeNode root){
        // if(root == null){
        //     return 0;
        // }
        // else{
        //     return size(root.left) + size(root.right) + 1;
        // }
        return root == null ? 0 : size(root.left) + size(root.right) + 1;
    }

    public static int height(TreeNode root){
        // if(root == null){
        //     return -1;
        // }
        // int left = height(root.left);
        // int right = height(root.right);
        // return Math.max(left, right) + 1;
        return root == null ? -1 : Math.max(root.val,Math.max(height(root.left), height(root.right)));
    }

    public static int maximum(TreeNode root){
        // if(root == null)
        //     return (int)1e9;
        // int lt = maximum(root.left);
        // int rt = maximum(root.right);
        // return Math.max(root.val,Math.max(lt, rt)); 
        return root == null ? -(int)1e9 : Math.max(root.val,Math.max(maximum(root.left),maximum(root.right)));
    }
    public static int minimum(TreeNode root){
        return root == null ? (int)1e9 : Math.min(root.val, Math.min(minimum(root.left), minimum(root.right)));
    }

    //---------------------------------------- Binary Tree Find Set ---------------------------------------------//

    public static boolean find(TreeNode root, int data){
        if(root == null){
            return false;
        }
        if(root.val == data){
            return true;
        }

        return find(root.left, data) || find(root.right, data);
    }

    public static boolean rootToNodePath(TreeNode root, int data,ArrayList<TreeNode>ans){
        if(root == null){
            return false;
        }
        if(root.val == data){
            ans.add(root);
        }

        boolean res = rootToNodePath(root.left, data, ans) || rootToNodePath(root.right, data, ans);
        if(res){
            ans.add(root);
        }
        return res;
    }
    public static void main(String[] args) {
         
    }
}

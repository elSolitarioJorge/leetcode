class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return dfs(nums, 0, nums.length);
    }

    private TreeNode dfs(int[] nums, int left, int right) {
        if (left == right) {
            return null;
        }
        int mid = left + (right - left) / 2;
        return new TreeNode(nums[mid], dfs(nums, left, mid), dfs(nums, mid + 1, right));
    }
}
    
    
class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        int n = nums1.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> nums2[i] - nums2[j]);
        int[] ans = new int[n];
        int left = 0, right = n - 1;
        for (int x : nums1) {
            int i = x > nums2[idx[left]] ? idx[left++] : idx[right--];
            ans[i] = x;
        }
        return ans;
    }
}
    
    
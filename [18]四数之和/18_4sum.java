class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        for (int a = 0; a < n - 3; a++) {
            long x = nums[a];
            if (a > 0 && x == nums[a - 1]) continue;
            if (x + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
            if (x + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            for (int b = a + 1; b < n - 2; b++) {
                long y = nums[b];
                if (b > a + 1 && y == nums[b - 1]) continue;
                if (x + y + nums[b + 1] + nums[b + 2] > target) break;
                if (x + y + nums[n - 2] + nums[n - 1] < target) continue;
                int c = b + 1;
                int d = n - 1;
                while (c < d) {
                    long s = x + y + nums[c] + nums[d];
                    if (s > target) d--;
                    else if (s < target) c++;
                    else {
                        ans.add(List.of((int) x, (int) y, nums[c], nums[d]));
                        for (c++; c < d && nums[c] == nums[c - 1]; c++) ;
                        for (d--; d > c && nums[d] == nums[d + 1]; d--) ;
                    }
                }
            }
        }
        return ans;
    }
}
    
    
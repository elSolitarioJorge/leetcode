class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    private int[] nums;

    public List<List<Integer>> findSubsequences(int[] nums) {
        this.nums = nums;
        dfs(0);
        return res;
    }

    private void dfs(int i) {
        if (path.size() > 1) {
            res.add(new ArrayList<>(path));
        }

        int[] map = new int[201];
        for (int j = i; j < nums.length; j++) {
            if (!path.isEmpty() && path.get(path.size() - 1) > nums[j] || map[nums[j] + 100] == 1) {
                continue;
            }
            map[nums[j] + 100] = 1;
            path.add(nums[j]);
            dfs(j + 1);
            path.removeLast();
        }
    }
}

class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    private int[] nums;

    public List<List<Integer>> findSubsequences(int[] nums) {
        this.nums = nums;
        dfs(0, -1);
        return res;
    }

    private void dfs(int i, int end) {
        if (i == nums.length) {
            if (path.size() > 1) {
                res.add(new ArrayList<>(path));
            }
            return;
        }

        dfs(i + 1, end);

        if (!path.isEmpty() && path.get(path.size() - 1) > nums[i] || !isValid(i, end)) {
            return;
        }
        path.add(nums[i]);
        dfs(i + 1, i);
        path.removeLast();
    }

    private boolean isValid(int pos, int end) {
        for (int i = end + 1; i < pos; i++) {
            if (nums[i] == nums[pos]) {
                return false;
            }
        }
        return true;
    }
}
    
    
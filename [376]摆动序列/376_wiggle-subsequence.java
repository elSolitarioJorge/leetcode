class Solution {
    public int wiggleMaxLength(int[] nums) {
        List<Integer> diff = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            int num = nums[i] - nums[i - 1];
            if (diff.size() == 0 && num != 0 || diff.size() > 0 && diff.getLast() * num < 0) {
                diff.add(num);
            }
        }
        return diff.size() + 1;
    }
}

class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length < 2) {
            return nums.length;
        }
        int preDiff = nums[1] - nums[0];
        int count = preDiff != 0 ? 2 : 1;
        for (int i = 2; i < nums.length; i++) {
            int diff = nums[i] - nums[i - 1];
            if (preDiff == 0 && diff != 0 || diff * preDiff < 0) {
                count++;
                preDiff = diff;
            }
        }
        return count;
    }
}
    
    
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
        int count = 0;
        int pre = Integer.MIN_VALUE;
        for (int[] i : intervals) {
            if (i[0] >= pre) {
                count++;
                pre = i[1];
            }
        }
        return intervals.length - count;
    }
}
    
    
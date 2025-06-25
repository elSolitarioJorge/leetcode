class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int res = 0;
        long pre = Long.MIN_VALUE;
        for (int[] p : points) {
            if (p[0] > pre) {
                res++;
                pre = p[1];
            }
        }
        return res;
    }
}
    
    
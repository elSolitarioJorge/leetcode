class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> res = new ArrayList<>();
        for (int[] i : intervals) {
            if (res.size() > 0 && i[0] <= res.getLast()[1]) {
                res.getLast()[1] = Math.max(res.getLast()[1], i[1]);
            } else {
                res.add(i);
            }
        }
        return res.toArray(new int[res.size()][]);
    }
}
    
    
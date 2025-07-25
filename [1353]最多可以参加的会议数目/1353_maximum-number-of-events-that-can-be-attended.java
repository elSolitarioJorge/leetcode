class Solution {
    public int maxEvents(int[][] events) {
        int mx = 0;
        for (int[] e : events) {
            mx = Math.max(mx, e[1]);
        }

        List<Integer>[] groups = new ArrayList[mx + 1];
        Arrays.setAll(groups, i -> new ArrayList<>());
        for (int[] e : events) {
            groups[e[0]].add(e[1]);
        }

        int ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i <= mx; i++) {
            while (!pq.isEmpty() && pq.peek() < i) {
                pq.poll();
            }
            for (int endDay : groups[i]) {
                pq.offer(endDay);
            }
            if (!pq.isEmpty()) {
                ans++;
                pq.poll();
            }
        }
        return ans;
    }
}
    
    
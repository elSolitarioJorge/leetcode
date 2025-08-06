class MinStack {

    private final Deque<int[]> stack = new ArrayDeque<>();

    public MinStack() {
        stack.push(new int[]{0, Integer.MAX_VALUE});
    }

    public void push(int val) {
        stack.push(new int[]{val, Math.min(getMin(), val)});
    }

    public void pop() {
        stack.pop();
    }

    public int top() {
        return stack.peek()[0];
    }

    public int getMin() {
        return stack.peek()[1];
    }
}
    
    
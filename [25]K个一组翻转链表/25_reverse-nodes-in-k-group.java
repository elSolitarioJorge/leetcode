class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int len = 0;
        ListNode cur = head;
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode node = dummy;
        ListNode pre = null;
        cur = head;
        for (; len >= k; len -= k) {
            for (int i = 0; i < k; i++) {
                ListNode temp = cur.next;
                cur.next = pre;
                pre = cur;
                cur = temp;
            }
            ListNode temp = node.next;
            temp.next = cur;
            node.next = pre;
            node = temp;
        }
        return dummy.next;
    }
}
    
    
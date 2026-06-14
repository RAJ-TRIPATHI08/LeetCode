/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int pairSum(ListNode head) {
        Stack<Integer> st = new Stack<>();

        ListNode temp = head;

        while(temp != null)
        {
            st.push(temp.val);
            temp = temp.next;
        }

        int pSum = 0;

        while(head != null && !st.empty())
        {
            pSum = Math.max(pSum, head.val + st.peek());
            st.pop();
            head = head.next;
        }

        return pSum;
    }
}
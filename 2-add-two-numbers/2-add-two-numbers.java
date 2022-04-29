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
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int carry = 0;
		ListNode head = new ListNode();
		ListNode ll = head;
		while (l1 != null && l2 != null) {
			int value = l1.val + l2.val + carry;
			carry = value / 10;
			value = value % 10;
			ll.next = new ListNode(value);

			// padding
			if (l1.next == null && l2.next != null) { l1.next = new ListNode(); }
			if (l2.next == null && l1.next != null) { l2.next = new ListNode(); }
			
			l1 = l1.next; l2 = l2.next; ll = ll.next;
		}
		if (carry > 0) ll.next = new ListNode(carry);
		return head.next;
	}
}
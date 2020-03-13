/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true; 
        ListNode fast = head; 
        ListNode slow = head; 
        while (fast != null && fast.next != null){
            slow = slow.next ; 
            fast = fast.next.next ; 
        }
        if (fast != null){
            slow = slow.next ; 
        }
        slow = reverse(slow);
        while (slow != null){
            if (head.val != slow.val) return false ; 
            head = head.next ; 
            slow = slow.next ;
        }
        return true; 
    }
    public ListNode reverse(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
}

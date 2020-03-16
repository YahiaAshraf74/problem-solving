/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode cum = null ;
        while(head != null){
            ListNode newNode = new ListNode(head.val) ;
            newNode.next = cum ;
            cum = newNode ;
            head = head.next ; 
        }
        return cum ;
    }
}

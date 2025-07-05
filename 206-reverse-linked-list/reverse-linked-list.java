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
    ListNode fun(ListNode curr,ListNode prev){
        if(curr==null){
            return prev;
        }
        ListNode temp=curr.next;
        curr.next=prev;
        return fun(temp,curr);

    }
    public ListNode reverseList(ListNode head) {
        ListNode curr=head;
        ListNode prev=null;
        ListNode ans=fun(curr,prev);
        return ans;
    }
}
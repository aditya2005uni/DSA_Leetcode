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
    public ListNode reverseList(ListNode head) {
        ListNode prev=null;
        ListNode curr=head;
        ListNode next=null;
        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
}



























// class Solution {
//     public ListNode fun(ListNode curr,ListNode prev){
//         if(curr==null){
//             return prev;
//         }
//         ListNode temp=curr.next;
//         curr.next=prev;
//         return fun(temp,curr);
//     }

//     public ListNode  reverseList(ListNode  head) {
//         ListNode curr=head;
//         ListNode  prev=null;
//         return fun(curr,prev);
        
    
//     }
// };
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
    public ListNode partition(ListNode head, int x) {
        if(head == null)return head;
        ListNode dummyHeadSml = new ListNode();
        ListNode curSmlNode = dummyHeadSml;

        ListNode dummyHeadEg = new ListNode();
        ListNode curEgNode = dummyHeadEg;

        for(ListNode curr = head; curr != null;){
            ListNode next = curr.next;
            curr.next = null;
            if(curr.val < x){
                curSmlNode.next = curr;
                curSmlNode = curr;
            }else{
                curEgNode.next = curr;
                curEgNode = curr;
            }
            curr = next;
        }
        
        curSmlNode.next = dummyHeadEg.next;
        return dummyHeadSml.next;
    }
}
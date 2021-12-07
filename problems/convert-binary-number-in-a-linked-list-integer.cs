/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public int GetDecimalValue(ListNode head) {
        int ret = 0;
        
        while(head != null){
            ret = ret * 2 + head.val;
            head = head.next;
        }
        return ret;
    }
}

/*
    Complexity analysis:
    Time: O(n), where `n` is the length of the linked list, as we need to scan every element.
    Space: O(1), since we do not use any extra space. 
*/

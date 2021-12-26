/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function oddEvenList(head: ListNode | null): ListNode | null {
    if (head === null) return null;     // 0 length
    if (head.next === null) return head;    // 1 length
    if (head.next.next === null) return head;   // 2 length
    
    // length >= 3
    let curr: ListNode = head.next.next;      // start at 3rd item
    const oddHead: ListNode = new ListNode(head.val);      // item 1
    let oddList: ListNode = oddHead;    // odd list iterator
    const evenHead: ListNode = new ListNode(head.next.val);      // item 2
    let evenList: ListNode = evenHead;      // even list iterator
    
    while (curr !== null || curr.val !== 0) {
        oddList.next = new ListNode(curr.val);
        oddList = oddList.next;
        curr = curr.next;
        if (curr === null) break;
        evenList.next = new ListNode(curr.val);
        curr = curr.next;
        evenList = evenList.next;
        if (curr === null) break;
    }
    
    oddList.next = evenHead;    // connect odd list end to even list head
    return oddHead;
};
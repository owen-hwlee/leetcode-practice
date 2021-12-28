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

function middleNode(head: ListNode | null): ListNode | null {
    
    // linked list node iterator
    let curr: ListNode = head;
    // running variable to store current middle node
    let mid: ListNode = head;
    // count number of nodes traversed
    let count: number = 1;
    
    while (curr.next !== null) {
        // increase count when traversed
        count++;
        // update middle node if required
        if (!(count % 2)) {
            mid = mid.next;
        }
        // update iterator
        curr = curr.next;
    }
    return mid;
};
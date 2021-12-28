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

function deleteMiddle(head: ListNode | null): ListNode | null {
    
    if (head.next === null) return null;

    // linked list node iterator
    let curr: ListNode = head;
    // running variable to store current middle node
    let mid: ListNode = head;
    // running variable to store prev of middle node
    let prev: ListNode = head;
    // count number of nodes traversed
    let count: number = 1;
    
    // find required nodes
    while (curr.next !== null) {
        // increase count when traversed
        count++;
        // update middle and prev node if required
        if (!(count % 2)) {
            if (count > 2) {
                prev = mid;
            }
            mid = mid.next;
        }
        // update iterator
        curr = curr.next;
    }
    
    // delete middle node
    prev.next = mid.next;
    
    return head;
};
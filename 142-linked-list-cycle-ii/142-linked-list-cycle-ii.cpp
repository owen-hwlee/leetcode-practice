/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;
        while (head != nullptr) {
            // not traversed yet
            if (nodeSet.find(head) == nodeSet.end()) {
                // add to map
                nodeSet.insert(head);
            } else {    // traversed already = have loop
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
};
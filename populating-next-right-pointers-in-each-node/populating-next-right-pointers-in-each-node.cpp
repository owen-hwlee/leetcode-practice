/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // handle root, root->next already NULL
        // recursively handle all remaining nodes
        perform(root, root, root);
        
        return root;
    }
    
    // helper function, recursive
    void perform(Node* &root, Node* &curr, Node* &parent) {
        // base case, out of range
        if (curr == NULL) return;
        
        // at a particular node, assign NEXT
        if (curr == parent->left) {
            // left node
            // next node is corresponding right node
            curr->next = parent->right;
        } else if (curr == parent->right) {
            // right node
            // next is next left when parent has next
            if (parent->next != NULL) {
                curr->next = parent->next->left;
            }
            // next is null when parent does not have next
            else {
                curr->next = NULL;
            }
        }
        
        // handle children nodes
        perform(root, curr->left, curr);
        perform(root, curr->right, curr);
    }
};
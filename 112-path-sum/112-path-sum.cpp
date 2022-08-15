/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // check if tree is empty
        if (root == nullptr) {
            return false;
        }
        
        return hasSum(root, targetSum);
    }
    
private:
    inline bool hasSum(TreeNode* node, int remainingSum) {
        // check for leaf node
        if (node->left == nullptr && node->right == nullptr) {
            return remainingSum == node->val;      // remaining sum == 0 if all values add up
        }
        
        return (node->left ? hasSum(node->left, remainingSum - node->val) : false)
            || (node->right ? hasSum(node->right, remainingSum - node->val) : false);
    }
};
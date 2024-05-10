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
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBSTUtil(TreeNode* node, long min, long max) {
        if (node == nullptr) {
            return true;
        }
        if (node->val <= min || node->val >= max) {
            return false;
        }
        return isValidBSTUtil(node->left, min, node->val) && isValidBSTUtil(node->right, node->val, max);
    }
};

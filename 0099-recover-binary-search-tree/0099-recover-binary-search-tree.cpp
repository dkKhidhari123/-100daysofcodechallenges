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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        inorder(root, prev, first, second);
        swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, prev, first, second);
        if (prev != nullptr && prev->val > node->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = node;
        }
        prev = node;
        inorder(node->right, prev, first, second);
    }
};

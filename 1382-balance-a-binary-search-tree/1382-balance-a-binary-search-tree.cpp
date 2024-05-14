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
    vector<TreeNode*> nodes;
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode* build(int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = nodes[mid];
        node->left = build(start, mid - 1);
        node->right = build(mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};

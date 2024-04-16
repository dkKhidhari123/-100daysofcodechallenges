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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        insert(v, root, 1, d);
        return root;
    }

private:
    void insert(int val, TreeNode* node, int depth, int n) {
        if (node == nullptr)
            return;
        if (depth < n - 1) {
            insert(val, node->left, depth + 1, n);
            insert(val, node->right, depth + 1, n);
        }
        else {
            TreeNode* t = node->left;
            node->left = new TreeNode(val);
            node->left->left = t;
            t = node->right;
            node->right = new TreeNode(val);
            node->right->right = t;
        }
    }
};

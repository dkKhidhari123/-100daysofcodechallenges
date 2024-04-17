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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }

private:
    string dfs(TreeNode* node, string s) {
        if (!node) return "|";
        s = string(1, 'a' + node->val) + s;
        if (!node->left && !node->right) return s;
        return min(dfs(node->left, s), dfs(node->right, s));
    }
};

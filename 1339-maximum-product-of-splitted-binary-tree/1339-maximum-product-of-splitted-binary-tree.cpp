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
    int maxProduct(TreeNode* root) {
        long total = 0, res = 0;
        total = dfs(root, total);
        dfs(root, total, res);
        return res % int(1e9+7);
    }

private:
    long dfs(TreeNode* root, long& total) {
        if (!root) return 0;
        total += root->val;
        return dfs(root->left, total) + dfs(root->right, total) + root->val;
    }

    long dfs(TreeNode* root, long total, long& res) {
        if (!root) return 0;
        long sub = dfs(root->left, total, res) + dfs(root->right, total, res) + root->val;
        res = max(res, sub * (total - sub));
        return sub;
    }
};

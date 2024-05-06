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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int rows = height;
        int cols = (1 << height) - 1; 
        vector<vector<string>> res(rows, vector<string>(cols, ""));
        fill(res, root, 0, rows, 0, cols - 1);
        return res;
    }

private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void fill(vector<vector<string>>& res, TreeNode* node, int row, int totalRows, int i, int j) {
        if (row == totalRows || node == nullptr) return;
        res[row][(i + j) / 2] = to_string(node->val);
        fill(res, node->left, row + 1, totalRows, i, (i + j) / 2 - 1);
        fill(res, node->right, row + 1, totalRows, (i + j) / 2 + 1, j);
    }
};

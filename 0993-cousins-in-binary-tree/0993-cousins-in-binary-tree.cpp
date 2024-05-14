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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        pair<int, TreeNode*> xData = {-1, nullptr}, yData = {-1, nullptr};
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                if (node->val == x) {
                    xData = {depth, parent};
                }
                if (node->val == y) {
                    yData = {depth, parent};
                }
                if (node->left) {
                    q.push({node->left, node});
                }
                if (node->right) {
                    q.push({node->right, node});
                }
            }
            if (xData.first != -1 && yData.first != -1) {
                break;
            }
            depth++;
        }
        return xData.first == yData.first && xData.second != yData.second;
    }
};

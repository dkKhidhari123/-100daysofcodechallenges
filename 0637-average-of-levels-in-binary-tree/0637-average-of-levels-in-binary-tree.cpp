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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()) {
            long temp = 0;
            int s = q.size();
            for(int i = 0; i < s; i++) {
                TreeNode* t = q.front();
                q.pop();
                temp += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            result.push_back(static_cast<double>(temp) / s);
        }
        return result;
    }
};

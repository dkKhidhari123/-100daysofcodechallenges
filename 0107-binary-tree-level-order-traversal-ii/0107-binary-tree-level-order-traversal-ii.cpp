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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         if(root == nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        stack<vector<int>> s;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                
                level.push_back(node->val);
            }
            
            s.push(level);
        }
        
        while(!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }
};
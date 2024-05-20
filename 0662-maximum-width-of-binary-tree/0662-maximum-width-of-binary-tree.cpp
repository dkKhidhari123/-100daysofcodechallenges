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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int maxWidth = 0;
        queue<pair<TreeNode*, long long>> q; 
        q.push({root, 1});
        
        while(!q.empty()) {
            int size = q.size();
            long long start = q.front().second; 
            long long end = q.back().second; 
            maxWidth = max(maxWidth, static_cast<int>(end - start + 1));
            
            for(int i = 0; i < size; i++) {
                pair<TreeNode*, long long> p = q.front(); 
                TreeNode* node = p.first;
                long long index = p.second - start; 
                q.pop();
                
                if(node->left != nullptr) q.push({node->left, 2 * index + 1});
                if(node->right != nullptr) q.push({node->right, 2 * index + 2});
            }
        }
        
        return maxWidth;
    }
};

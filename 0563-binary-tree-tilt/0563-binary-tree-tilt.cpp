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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        postOrder(root, tilt);
        return tilt;
        
    }
    
    private:
        int postOrder(TreeNode* node, int& tilt) {
            if(!node) return 0;
            int left = postOrder(node->left, tilt);
            int right = postOrder(node->right, tilt);
            tilt += abs(left - right);
            return left + right + node->val;
        }
};
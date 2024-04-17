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
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestHelper(root, k);
    }
private:
    int kthSmallestHelper(TreeNode* root, int& k) {
        if (root) {
            int x = kthSmallestHelper(root->left, k);
            if(k == 0) return x;
            if(--k == 0) return root->val;
            return kthSmallestHelper(root->right, k);
        }
        return -1;
    }
};

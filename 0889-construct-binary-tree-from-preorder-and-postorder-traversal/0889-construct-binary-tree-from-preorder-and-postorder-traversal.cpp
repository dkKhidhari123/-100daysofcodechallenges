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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(pre, 0, pre.size(), post, 0, post.size());
    }

private:
    TreeNode* construct(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd) {
        if (preStart >= preEnd || postStart >= postEnd) return nullptr;
        TreeNode* root = new TreeNode(pre[preStart]);
        if (preEnd - preStart == 1) return root;
        int leftRootVal = pre[preStart + 1];
        int leftSubTreeSize = find(post.begin() + postStart, post.begin() + postEnd, leftRootVal) - (post.begin() + postStart) + 1;
        root->left = construct(pre, preStart + 1, preStart + 1 + leftSubTreeSize, post, postStart, postStart + leftSubTreeSize);
        root->right = construct(pre, preStart + 1 + leftSubTreeSize, preEnd, post, postStart + leftSubTreeSize, postEnd - 1);
        return root;
    }
};

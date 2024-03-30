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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    
    private:
        TreeNode* build(vector<int>& nums, int l, int r) {
            if (l > r) {
                return nullptr;
            }
            int maxIndex = max_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();
            TreeNode* root = new
                TreeNode(nums[maxIndex]);
            root->left = build(nums, l, maxIndex - 1);
            root->right = build(nums, maxIndex + 1, r);
            return root;
        }
};
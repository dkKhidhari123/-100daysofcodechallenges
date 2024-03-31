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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         return sortedArrayToBST(nums.begin(), nums.end());
    }

private:
    template <typename RandomAccessIterator>
    TreeNode* sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last) {
        const auto length = distance(first, last);
        if (length <= 0) return NULL;
        auto root = new TreeNode(0);
        root->left = sortedArrayToBST(first, first + length / 2);
        root->val = *(first + length / 2);
        root->right = sortedArrayToBST(first + length / 2 + 1, last);
        return root;
    }
};
        
    
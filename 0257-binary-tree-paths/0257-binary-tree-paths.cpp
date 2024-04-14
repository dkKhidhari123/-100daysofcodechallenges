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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root)  dfs(root, "", paths);
        return paths;
    }
    
    private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        path += to_string(node->val);
        if(!node->left && !node->right) {
            paths.push_back(path);
            return;
        }
        if(node->left) dfs(node->left, path + "->", paths);
        if(node->right) dfs(node->right, path + "->", paths);
    }
};
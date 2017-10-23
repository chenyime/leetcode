/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int bottomLeft = 0;
        int height = 0;
        dfs(root, 1, height, bottomLeft);
        return bottomLeft;
    }

private:
    void dfs(TreeNode* node, int depth, int& height, int& res) {
        if (!node) {
            return;
        }
        if (depth > height) {
            res = node->val;
            height = depth;
        }
        dfs(node->left, depth + 1, height, res);
        dfs(node->right, depth + 1, height, res);
    }
};
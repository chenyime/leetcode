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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        dfs(root, depth, 1);
        return depth;
    }
    
    void dfs(TreeNode* node, int& depth, int now) {
        if (node == NULL)
            return;
        if (depth < now)
            depth = now;
        dfs(node->left, depth, now+1);
        dfs(node->right, depth, now+1);
    }
};
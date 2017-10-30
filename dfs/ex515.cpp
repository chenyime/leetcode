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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res; 
        int height = 0;
        dfs(root, 1, height, res);
        return res;
    }
    
private:
    void dfs(TreeNode* node, int depth, int& height, vector<int>& res) {
        if (!node) {
            return;
        }
        if (depth > height) {
            res.push_back(node->val);
            height = depth;
        } else {
            if (res[depth-1] < node->val) {
                res[depth-1] = node->val;
            }
        }
        dfs(node->left, depth + 1, height, res);
        dfs(node->right, depth + 1, height, res);
    }
};
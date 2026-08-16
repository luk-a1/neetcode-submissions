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
class Solution 
{
    pair<int, int> dfs(TreeNode* root){    
        if(!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        return {
            root->val + left.second + right.second,
            max(left.first, left.second) + max(right.first, right.second)
        };   
    }

public:
    int rob(TreeNode* root) {
        auto a = dfs(root);
        return max(a.first, a.second);
    }
};
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
    vector<int> dfs(TreeNode* root){
        if(root == nullptr) return {0, -1};

        vector<int> right = dfs(root->right);
        vector<int> left = dfs(root->left);

        return {max(right[1] + left[1] + 2, max(right[0], left[0])), 1 + max(right[1], left[1])};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> out = dfs(root);
        return out[0];
    }
};

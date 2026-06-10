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
    int cnt = 0;

    void dfs(TreeNode* node, int curmax){
        if(node == nullptr) return;
        if(node->val >= curmax){
            cnt++;
            curmax = node->val;
        }
        dfs(node -> right, curmax);
        dfs(node -> left, curmax);
        

    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return cnt;
    }
};

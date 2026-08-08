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
    void dfs(TreeNode* root, vector<int>& output){
        if(root == nullptr) return;
        //if(root->right==nullptr && root->left == nullptr) output.push_back(root->val);
        if(root->left) dfs(root->left, output);
        if(root->right) dfs(root->right, output);
        output.push_back(root->val); 
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        dfs(root, output);
        return output;
    }
};
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

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(root == nullptr) 
            return root;

        if(root->val == target && root->right == nullptr && root->left == nullptr)
        {
            delete root;
            return nullptr;
        }

        TreeNode* left_res = removeLeafNodes(root->left, target);
        TreeNode* right_res = removeLeafNodes(root->right, target);
        root->left = left_res;
        root->right = right_res;
        if(left_res == nullptr && right_res == nullptr && root->val == target) 
        {
            delete root;
            return nullptr;
        }
        return root;
    }
};
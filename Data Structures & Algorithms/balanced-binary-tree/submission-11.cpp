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

    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int left=0, right=0;
        if(root->left != nullptr) left = 1+height(root->left);
        if(root->right != nullptr) right = 1+height(root->right);
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int right = 0;
        int left = 0;
        if(root->right) right = 1 + height(root->right);
        if(root->left) left = 1+height(root->left);
        if(abs(left-right) > 1) return false;
        bool lbal = true;
        bool rbal = true;
        if(root->left != nullptr) lbal = isBalanced(root->left);
        if(root->right != nullptr) rbal = isBalanced(root->right);
        return lbal && rbal;
    }
};

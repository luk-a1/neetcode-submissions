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
    TreeNode* dfs(int root, int left, int right, vector<int>& inorder, vector<int>& preorder)
    {
        
        if(right < 0 || left > inorder.size()-1 || left > right) return nullptr;
        TreeNode* left_node;
        TreeNode* right_node;
        for(int i=left; i <= right; i++){
            if(inorder[i] == preorder[root]){
                left_node = dfs(root+1, left, i-1, inorder, preorder);
                right_node = dfs(root+i-left+1, i+1, right, inorder, preorder);
                break;
            }
        }

        return new TreeNode(preorder[root], left_node, right_node);
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0, 0, inorder.size()-1, inorder, preorder);
    }
};

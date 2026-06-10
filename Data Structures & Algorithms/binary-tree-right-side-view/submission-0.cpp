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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        vector<int> levels;
        q.push({root, 1});
        //levels.push_back(1);

        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(curr == nullptr) continue;

            if(levels.size() < lvl) levels.push_back(curr->val);
            else levels[lvl-1] = curr->val;

            q.push({curr->left, lvl+1});
            q.push({curr->right, lvl+1});


            /*
            if(levels.size()<lvl)
            q.pop();
            if(curr -> left != nullptr){
                q.push({curr->left, lvl+1});
                if(levels.size() < lvl+1) levels.push_back(curr->val);
                else levels[lvl] = curr -> val;
            }
            
            if(curr -> right != nullptr){
                q.push({curr->right, lvl+1});
                if(levels.size() < lvl+1) levels.push_back(curr->val);
                else levels[lvl] = curr -> val;
            }

            */
        }

        return levels;
    }
};

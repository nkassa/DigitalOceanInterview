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
    vector<int> ans;
    bool isValidBST(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }
        dfs(root);
        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i-1] >= ans[i])
            {
                return false;
            }
        }
        return true;
    }
    void dfs(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    } 
};
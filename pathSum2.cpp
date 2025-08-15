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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> curr;
        dfs(root, targetSum, curr);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, vector<int> curr)
    {
        if(!root)
        {
            return;
        }
        curr.push_back(root->val);
        targetSum -= root->val;
        if(!root->left && !root->right && targetSum == 0)
        {
            ans.push_back(curr);
        }
        dfs(root->left, targetSum, curr);
        dfs(root->right, targetSum, curr);
    }
};
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        dfs(root1);
        dfs(root2);
        sort(ans.begin(), ans.end());
        return ans;
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
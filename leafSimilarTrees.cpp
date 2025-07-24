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
    vector<int> list;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> one;
        vector<int> two;
        dfs(root1);
        one = list;
        list.clear();
        dfs(root2);
        two = list;
        return one == two;
    }
    void dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            list.push_back(root->val);
        }
        dfs(root->left);
        dfs(root->right);
    }
};
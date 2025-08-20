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
    int maxLevelSum(TreeNode* root) 
    {
        int level = 1;
        int maxi = INT_MIN;
        int curr = 0;
        int ans = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            int size = queue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                curr += node->val;
                queue.pop();
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
            }
            if(maxi  < curr)
            {
                maxi = curr;
                ans = level;
            }
            curr = 0;
            level++;
        }
        return ans;
    }
};
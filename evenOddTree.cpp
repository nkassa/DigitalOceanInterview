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
    bool isEvenOddTree(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }
        vector<vector<int>> graph;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            int size = queue.size();
            vector<int> curr;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                curr.push_back(node->val);
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
            }
            graph.push_back(curr);
        }
        for(int i = 0; i < graph.size(); i++)
        {
            if(i % 2 == 0)
            {
                if(graph[i][0]% 2 == 0)
                {
                    return false;
                }
                for(int j = 1; j < graph[i].size(); j++)
                {
                    if(graph[i][j]% 2 == 0 || graph[i][j-1] >= graph[i][j])
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(graph[i][0]% 2 != 0)
                {
                    return false;
                }
                for(int j = 1; j < graph[i].size(); j++)
                {
                    if(graph[i][j]% 2 != 0 || graph[i][j-1] <= graph[i][j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
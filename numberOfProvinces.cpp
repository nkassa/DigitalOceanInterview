class Solution {
public:
    int m;
    int n;
    vector<bool> seen;
    vector<vector<int>> graph;
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        m = isConnected.size();
        n = isConnected[0].size();
        seen = vector<bool>(n, false);
        graph = vector(n);
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(isConnected[row][col] == 1)
                {
                    graph[row].push_back(col);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < seen.size(); i++)
        {
            ans++;
            seen[i] = true;
            dfs(i);
        }
        return ans;
    }
    void dfs(int row)
    {
        for(int neig: graph[row])
        {
            seen[neig] = true;
        }
    }
};
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
    {
        vector<vector<int>> ans;
        for(vector<int> row: image)
        {
            reverse(row.begin(), row.end());
            ans.push_back(row);
        }
        for(int row = 0; row < ans.size(); row++)
        {
            for(int col = 0; col < ans[0].size(); col++)
            {
                if(ans[row][col] == 1)
                {
                    ans[row][col] = 0;
                }
                else
                {
                    ans[row][col] = 1;
                }
            }
        }
        return ans;
    }
};
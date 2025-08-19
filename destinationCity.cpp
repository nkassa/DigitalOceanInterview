class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_set<string> seen;
        for(int i = 0; i < paths.size(); i++)
        {
            seen.insert(paths[i][0]);
        }
        for(int i = 0; i < paths.size(); i++)
        {
            if(seen.find(paths[i][1]) == seen.end())
            {
                return paths[i][1];
            }
        }
        return "";
    }
};
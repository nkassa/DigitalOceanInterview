class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> count;
        for(string str: strs)
        {
            string copy = str;
            sort(str.begin(), str.end());
            count[str].push_back(copy);
        }
        for(auto [key, value]: count)
        {
            ans.push_back(value);
        }
        return ans;
    }
};
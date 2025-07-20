class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> count;
        for(int i = 0; i < s.size(); i++)
        {
            count[s[i]] = i;
        }

        vector<int> ans;
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++)
        {
            end = max(end, count[s[i]]);
            if(i == end)
            {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string customSortString(string order, string s) 
    {
        unordered_map<char,int> seen;
        for(char c: s)
        {
            seen[c]++;
        }
        string ans = "";
        for(int i = 0; i < order.size(); i++)
        {
            while(seen[order[i]] > 0)
            {
                ans += order[i];
                seen[order[i]]--;
            }
        }
        for(auto [key, val]: seen)
        {
            for(int i= 0; i < val; i++)
            {
                ans += key;
            }
        }
        return ans;
    }
};
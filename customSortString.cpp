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
            if(seen.find(order[i]) != seen.end())
            {
                int size = seen[order[i]];
                for(int j = 0; j < size; j++)
                {
                    ans += order[i];
                    seen[order[i]]--;
                    if(seen[order[i]] == 0)
                    {
                        seen.erase(order[i]);
                    }
                }
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
class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> count = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for(int i = 0; i < s.size()-1; i++)
        {
            if(count[s[i]] < count[s[i+1]])
            {
                ans -= count[s[i]];
            }
            else
            {
                ans += count[s[i]];
            }
        }
        ans += count[s[s.size()-1]];
        return ans;
    }
};
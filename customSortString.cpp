class Solution {
public:
    string customSortString(string order, string s) 
    {
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
        }
        string ans = "";
        for(int i = 0; i < order.size(); i++)
        {
            while(count[order[i]] > 0)
            {
                ans += order[i];
                count[order[i]]--;
            }
        }
        for(auto [key,val]: count)
        {
            for(int i = 0; i < val; i++)
            {
                ans += key;
            }
        }
        return ans;
    }
};//
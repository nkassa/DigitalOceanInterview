class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int open = 0;
        vector<string> list;
        string curr = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                open--;
            }
            curr += s[i];
            if(open == 0)
            {
                list.push_back(curr);
                curr = "";
            }
        }
        string ans = "";
        for(string str: list)
        {
            int size = str.size();
            ans += str.substr(1, size-2);
        }
        return ans;
    }
};
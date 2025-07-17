class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        string str = s + s;
        int n = str.size();
        return str.substr(1, n-2).find(s) != -1;
    }
};
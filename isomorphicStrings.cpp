class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char> count;
        unordered_map<char, char> countTwo;
        for(int i = 0; i < s.size(); i++)
        {
            if(count.find(t[i]) != count.end() && count[t[i]] != s[i])
            {
                return false;
            }
            if(countTwo.find(s[i]) != countTwo.end() && countTwo[s[i]] != t[i])
            {
                return false;
            }
            count[t[i]] = s[i];
            countTwo[s[i]] = t[i];
        }
        string str = "";
        string strTwo = "";
        for(int i = 0; i < t.size(); i++)
        {
            str += count[t[i]];
        }
        for(int i = 0; i < s.size(); i++)
        {
            strTwo += countTwo[s[i]];
        }
        return str == s && strTwo == t;
    }
};
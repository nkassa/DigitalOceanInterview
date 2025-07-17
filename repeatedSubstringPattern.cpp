class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.size();
        for(int i = 1; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                string str = s.substr(0, i);
                while(str.size() < s.size())
                {
                    str += str;
                }
                if(str == s)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
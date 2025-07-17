class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.size();
        for(int i = 1; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                string str = "";
                string temp = s.substr(0, i);
                for(int j = 0; j < n/i; j++)
                {
                    str += temp;
                }
                cout << str << endl;
                if(str == s)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
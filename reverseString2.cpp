class Solution {
public:
    string reverseStr(string s, int k) 
    {
        string ans = "";
        int n = s.size();
        int idx = 0;
        while(idx < n)
        {
            string str = s.substr(idx, k);
            reverse(str.begin(), str.end());
            ans += str;
            if(idx + k < n) 
            {  
                ans += s.substr(idx + k, k);
            }
            idx += (2*k);
        }
        return ans;
    }
};
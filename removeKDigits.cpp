class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<char> st;
        for(char c: num)
        {
            while(k > 0 && !st.empty() && st.top() > c)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        int idx = ans.size()-1;
        while(idx >= 0 && ans[idx] == '0')
        {
            idx--;
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0)
        {
            return "0";
        }
        return ans;
    }
};
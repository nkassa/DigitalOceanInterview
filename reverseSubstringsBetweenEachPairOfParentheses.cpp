class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<char> stack;
        for(char c: s)
        {
            if(c != ')')
            {
                stack.push(c);
            }
            else
            {
                string temp;
                while(!stack.empty() && stack.top() != '(')
                {
                    temp += stack.top();
                    stack.pop();
                }
                stack.pop();
                for(char ch: temp)
                {
                    stack.push(ch);
                }
            }
        }
        string ans = "";
        while(!stack.empty())
        {
            ans += stack.top();
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


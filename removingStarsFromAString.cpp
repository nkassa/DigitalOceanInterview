class Solution {
public:
    string removeStars(string s) 
    {
        stack<int> stack;
        for(char c: s)
        {
            if(c != '*')
            {
                stack.push(c);
            }
            else
            {
                if(!stack.empty())
                {
                    stack.pop();
                }
            }
        }
        string ans(stack.size(), ' ');
        for(int i = stack.size()-1; i >= 0; i--)
        {
            ans[i] = stack.top();
            stack.pop();
        }
        return ans;
    }
};
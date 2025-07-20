class Solution {
public:
    bool isValid(string s) 
    {
        vector<char> stack;
        unordered_map<char,char> count = {{'}', '{'}, {')', '('}, {']', '['}};
        for(char c: s)
        {
            if(count.find(c) == count.end())
            {
                stack.push_back(c);
            }
            else
            {
                if(stack.size() > 0 && count[c] == stack.back())
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        return stack.size() == 0;
    }
};
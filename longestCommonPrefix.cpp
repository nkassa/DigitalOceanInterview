class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string curr = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            while(curr.size() > 0 && strs[i].find(curr) != 0)
            {
                curr.pop_back();
            }
            if(curr.size() == 0)
            {
                return "";
            }
        }
        return curr;
    }
};
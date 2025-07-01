class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s.size() != goal.size())
        {
            return false;
        }
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
            if(s == goal && count[c] > 1)
            {
                return true;
            }
        }
        vector<int> idx;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != goal[i])
            {
                idx.push_back(i);
            }
        }
        if(idx.size() == 2)
        {
            char temp = goal[idx[0]];
            goal[idx[0]] = goal[idx[1]];
            goal[idx[1]] = temp;
            if(s == goal)
            {
                return true;
            }
        }
        return false;
    }
};//
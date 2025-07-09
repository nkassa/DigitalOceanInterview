class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
        }
        for(char c: goal)
        {
            if(count.find(c) == count.end())
            {
                return false;
            }
            count[c]--;
            if(count[c] == 0)
            {
                count.erase(c);
            }
        } 
        return count.size() == 0;
    }
};
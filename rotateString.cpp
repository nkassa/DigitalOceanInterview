class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size() != goal.size())
        {
            return false;
        }
        int idxTwo = 0;
        while(idxTwo < goal.size())
        {
            if(s[0] == goal[idxTwo])
            {
                break;
            }
            idxTwo++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            idxTwo %= goal.size();
            if(s[i] != goal[idxTwo])
            {
                return false;
            }
            idxTwo++;
        }
        return true;
    }
};
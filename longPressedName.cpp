class Solution {
public:
    
    bool isLongPressedName(string name, string typed) 
    {
        int idx = 0;
        int i = 0;
        while(i < name.size())
        {
            if(idx >= typed.size())
            {
                return false;
            }
            if(name[i] == typed[idx])
            {
                i++;
                idx++;
            }
            else
            {
                idx++;
            }
        }
        return i == name.size();
    }
};
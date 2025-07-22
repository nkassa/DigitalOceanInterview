class Solution {
public:
    
    bool isLongPressedName(string name, string typed) 
    {
        int idx = 0;
        for(int i = 0; i < name.size(); i++)
        {
            if(idx >= typed.size())
            {
                return false;
            }
            while(name[i] != typed[idx])
            {
                idx++;
            }
        }
        return true;
    }
};
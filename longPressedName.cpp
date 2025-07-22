class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        int i = 0;
        int j = 0;
        while(j < typed.size())
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if(j > 0 && typed[j-1] == typed[j])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        return i == name.size();
    }
};
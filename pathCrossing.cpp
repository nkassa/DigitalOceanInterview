class Solution {
public:
    bool isPathCrossing(string path) 
    {
        unordered_set<string> seen;
        int x = 0;
        int y = 0;
        seen.insert("0,0");
        for(char c: path)
        {
            if(c == 'N')
            {
                y++;
            }
            else if(c == 'S')
            {
                y--;
            }
            else if(c == 'W')
            {
                x++;
            }
            else
            {
                x--;
            }
            string str = to_string(x) + ',' + to_string(y);
            if(seen.find(str) != seen.end())
            {
                return true;
            }
            seen.insert(str);
        }
        return false;
    }
};
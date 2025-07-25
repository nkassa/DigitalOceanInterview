class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string> list;
        stringstream ss(s);
        string temp = "";
        unordered_map<char, string> count;
        unordered_map<string, char> countTwo;
        while(getline(ss, temp, ' '))
        {
            list.push_back(temp);
        }
        if(pattern.size() != list.size())
        {
            return false;
        }
        for(int i = 0; i < pattern.size(); i++)
        {
            if(count.find(pattern[i]) != count.end())
            {
                if(count[pattern[i]] != list[i])
                {
                    return false;
                }
            }
            count[pattern[i]] = list[i];
        }
        for(int i = 0; i < list.size(); i++)
        {
            if(countTwo.find(list[i]) != countTwo.end())
            {
                if(countTwo[list[i]] != pattern[i])
                {
                    return false;
                }
            }
            countTwo[list[i]] = pattern[i];
        }
        return true;
    }
};
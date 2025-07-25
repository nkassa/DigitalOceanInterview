class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string> list;
        stringstream ss(s);
        string temp = "";

        while(getline(ss, temp, ' '))
        {
            list.push_back(temp);
        }

        if(pattern.size() != list.size())
        {
            return false;
        }

        unordered_map<char, string> count;
        unordered_map<string, char> countTwo;
        
        for(int i = 0; i < pattern.size(); i++)
        {
            if(count.find(pattern[i]) != count.end())
            {
                if(count[pattern[i]] != list[i])
                {
                    return false;
                }
            }
            if(countTwo.find(list[i]) != countTwo.end())
            {
                if(countTwo[list[i]] != pattern[i])
                {
                    return false;
                }
            }
            count[pattern[i]] = list[i];
            countTwo[list[i]] = pattern[i];
        }
        return true;
    }
};
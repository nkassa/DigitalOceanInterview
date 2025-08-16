class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string> str;
        unordered_map<char,string> count;
        unordered_map<string,char> countTwo;
        stringstream ss(s);
        string temp = "";
        while(getline(ss, temp, ' '))
        {
            str.push_back(temp);
        }
        if(pattern.size() != str.size())
        {
            return false;
        }
        for(int i = 0; i < pattern.size(); i++)
        {
            count[pattern[i]] = str[i];
            countTwo[str[i]] = pattern[i];
        }
        string check = "";
        string checkTwo = "";
        for(int i = 0; i < pattern.size(); i++)
        {
            check += count[pattern[i]];
            check += " ";
            checkTwo += countTwo[str[i]];
        }
        check.pop_back();
        return s == check && pattern == checkTwo;
    }
};
class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == ch)
            {
                string str = word.substr(0, i+1);
                reverse(str.begin(), str.end());
                string ans = str + word.substr(i+1, word.size()-i);
                return ans;
            }
        }
        return word;
    }
};
class Solution {
public:
    string reverseVowels(string s) 
    {
        unordered_set<char> seen = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            if(seen.find(s[right]) != seen.end() && seen.find(s[left]) != seen.end())
            {
                char c = s[left];
                s[left] = s[right];
                s[right] = c;
                left++;
                right--;
            }
            if(seen.find(s[right]) == seen.end())
            {
                right--;
            }
            if(seen.find(s[left]) == seen.end())
            {
                left++;
            }
        }
        return s;
    }
};
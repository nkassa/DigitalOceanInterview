class Solution {
public:
    string reverseVowels(string s) 
    {
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            if(s[right] != 'a' || s[right] != 'e' || s[right] != 'i' || s[right] != 'o' || s[right] != 'u')
            {
                right--;
            }
            if(s[left] != 'a' || s[left] != 'e' || s[left] != 'i' || s[left] != 'o' || s[left] != 'u')
            {
                left++;
            }
            if(isvowel(s[right]) && isvowel(s[left]))
            {
                char c = s[left];
                s[left] = s[right];
                s[right] = c;
                left++;
                right--;
            }
        }
        return s;
    }
};
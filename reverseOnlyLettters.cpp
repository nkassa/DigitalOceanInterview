class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        int left = 0;
        int right = s.size();
        while(left < right)
        {
            if(!isalpha(s[left]))
            {
                left++;
            }
            if(!isalpha(s[right]))
            {
                right--;
            }
            if(isalpha(s[right]) && isalpha(s[left]))
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        return s;
    }
};
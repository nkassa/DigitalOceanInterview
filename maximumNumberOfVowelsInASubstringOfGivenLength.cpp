class Solution {
public:
    unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
    int maxVowels(string s, int k) 
    {
        int left = 0;
        int vow = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++)
        {
            if(set.find(s[right]) != set.end())
            {
                vow++;
            }
            if(right-left+1 > k)
            {
                if(set.find(s[left]) != set.end())
                {
                    vow--;
                }
                left++;
            }
            ans = max(ans, vow);
        }
        return ans;
    }
};
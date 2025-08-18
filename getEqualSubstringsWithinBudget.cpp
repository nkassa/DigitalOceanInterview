class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int curr = 0;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++)
        {
            curr += abs(s[right] - t[right]);
            while(curr > maxCost)
            {
                curr -= abs(s[left] - t[left]);
                left++;
            }
            // plus one because zero idex
            ans = max(ans, right-left+1);
        }
        return ans;
        
    }
};
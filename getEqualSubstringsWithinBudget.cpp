class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int sum = 0;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++)
        {
            sum += abs(s[right] - t[right]);
            while(sum > maxCost && left <= right)
            {
                sum -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
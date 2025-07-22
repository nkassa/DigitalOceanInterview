class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int> clone = heights;
        sort(clone.begin(), clone.end());
        int ans = 0;
        int idx = 0;
        for(int num: heights)
        {
            if(clone[idx] != num)
            {
                ans++;
            }
            idx++;
        }
        return ans;
    }
};
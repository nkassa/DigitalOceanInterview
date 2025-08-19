class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int ans = 0;
        unordered_map<int,int> count;
        int maxi = 0;
        for(int num: nums)
        {
            count[num]++;
            maxi = max(maxi, count[num]);
        }
        for(auto [key,val]: count)
        {
            if(val == maxi)
            {
                ans += val;
            }
        }
        return ans;
    }
};
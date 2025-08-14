class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int ans = 1;
        int left = 0;
        for(int right = 1; right < nums.size(); right++)
        {
            if(nums[right] <= nums[right-1])
            {
                left = right;
            }
            ans = max(right-left+1, ans);
        }
        return ans;
    }
};
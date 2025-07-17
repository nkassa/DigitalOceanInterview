class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int ans = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
            {
                return i-1;
            }
            else
            {
                ans = i;
            }
        }
        return ans;
    }
};
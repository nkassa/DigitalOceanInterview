class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size()-1;
        vector<int> ans(nums.size(), 0);
        int idx = ans.size()-1;
        while(left <= right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans[idx] = pow(nums[left], 2);
                left++;
            }
            else
            {
                ans[idx] = pow(nums[right], 2);
                right--;
            }
            idx--;
        }
        return ans;
    }
};
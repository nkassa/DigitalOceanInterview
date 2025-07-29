class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n,0);
        int left = 0;
        int right = n-1;
        n = ans.size()-1;
        while(left <= right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans[n] = pow(nums[left], 2);
                left++;
            }
            else
            {
                ans[n] = pow(nums[right], 2);
                right--;
            }
            n--;
        }
        return ans;
    }
};
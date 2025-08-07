class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(left < right)
        {
            if(nums[left] % 2 > nums[right] % 2)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
            if(nums[left] % 2 == 0)
            {
                left++;
            }
            if(nums[right] % 2 != 0)
            {
                right--;
            }
        }
        return nums;
    }
};
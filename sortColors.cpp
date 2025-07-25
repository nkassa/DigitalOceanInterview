class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size()-1;
        int curr = 0;
        while(curr <= right)
        {
            if(nums[curr] == 0)
            {
                int temp = nums[left];
                nums[left] = nums[curr];
                nums[curr] = temp;
                curr++;
                left++;
            }
            else if(nums[curr] == 1)
            {
                curr++;
            }
            else
            {
                int temp = nums[right];
                nums[right] = nums[curr];
                nums[curr] = temp;
                right--;
            }
        }
    }
};
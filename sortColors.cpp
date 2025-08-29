class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        unordered_map<int,int> count;
        int start = 0;
        int end = 0;
        int left = 0;
        int right = nums.size()-1;
        for(int num: nums)
        {
            count[num]++;
        }
        for(int i = 0; i < count[2]; i++)
        {
            nums[right] = 2;
            right--;
            end = right;
        }
        for(int i = 0; i < count[0]; i++)
        {
            nums[left] = 0;
            left++;
            start = left;
        }
        for(int i = start; i <= end; i++)
        {
            nums[i] = 1;
        }
    }
};
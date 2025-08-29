class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        unordered_map<int,int> count;
        int left = 0;
        for(int num: nums)
        {
            count[num]++;
        }
        for(int i = 0; i < count[0]; i++)
        {
            nums[left] = 0;
            left++;
        }
        for(int i = 0; i < count[1]; i++)
        {
            nums[left] = 1;
            left++;
        }
        for(int i = 0; i < count[2]; i++)
        {
            nums[left] = 2;
            left++;
        }
    }
};
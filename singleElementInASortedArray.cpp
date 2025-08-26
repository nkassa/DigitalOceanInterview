class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        int single = 0;
        for(auto [key,val]: count)
        {
            if(val == 1)
            {
                single = key;
                break;
            }
        }
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == single)
            {
                return nums[mid];
            }
            else if(nums[mid] > single)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return 0;
    }
};
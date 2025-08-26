class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int left = 1;
        int right = 0;
        for(int num: nums)
        {
            right = max(num, right);
        }
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(check(mid, threshold, nums))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(int mid, int& limit, vector<int>& nums)
    {
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count += ceil((double)nums[i]/mid);
        }
        return count <= limit;
    }
};
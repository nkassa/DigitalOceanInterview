class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int left = 0;
        int right = 0;
        for(int num: nums)
        {
            right += num;
        }
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(check(mid, nums, k))
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
    bool check(int mid, vector<int>& nums, int& k)
    {
        int cnt = 1;
        int sum = 0;
        for(int i= 0; i < nums.size(); i++)
        {
            if(sum + nums[i] > mid)
            {
                cnt++;
                sum = nums[i];
                if(cnt > k)
                {
                    return false;
                }
            }
            else
            {
                sum += nums[i];
            }
        }
        return true;
    }
};
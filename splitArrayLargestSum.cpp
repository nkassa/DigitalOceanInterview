class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int left = 1;
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
        int cnt = 0;
        int sum = 0;
        for(int i= 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum >= mid)
            {
                cnt++;
                sum = 0;
            }
        }
        return cnt == k;
    }
};
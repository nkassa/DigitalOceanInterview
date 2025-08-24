class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int left = 1;
        int right = 0;
        int sum = 0;
        for(int num: nums)
        {
            right = max(num, right);
            sum += num;
        }
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(sum / mid < threshold)
            {
                left = mid + 1;
            }
            else if(sum / mid == threshold)
            {
                return mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
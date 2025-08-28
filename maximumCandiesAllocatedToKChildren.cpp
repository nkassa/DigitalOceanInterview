class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        long long left = 1;
        long long right = 0;
        for(int num: candies)
        {
            right = max(right, 1LL*num);
        }
        while(left <= right)
        {
            long long mid = left + (right - left) / 2;
            if(check(mid, candies, k))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right;
    }
    bool check(long long mid, vector<int>& candies, long long& k)
    {
        long long cnt = 0;
        for(int i = 0; i < candies.size(); i++)
        {
            cnt += candies[i] / mid;
        }
        return cnt >= k;
    }
};
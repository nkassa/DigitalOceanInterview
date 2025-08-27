class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long left = 1;
        long long right = LLONG_MAX;
        while(left <= right)
        {
            long long mid = left + (right-left)/2;
            if(check(mid, time, totalTrips))
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
    bool check(long long mid, vector<int>& time, int& totalTrips)
    {
        long long cnt = 0;
        for(int i = 0; i < time.size(); i++)
        {
            cnt += mid / time[i];
        }
        return cnt >= totalTrips;
    }
};
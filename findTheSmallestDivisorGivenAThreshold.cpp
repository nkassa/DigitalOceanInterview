class Solution {
public:
    int limit;
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        limit = threshold;
        int left = 1;
        int right = 0;
        for(auto num: nums)
        {
            right = max(right, num);
        }
        cout << left << " " << right << endl;
        while(left <= right)
        {
            int mid = left + (right-left) / 2;
            if(check(mid, nums))
            {
                cout << "right " << mid << endl;
                right = mid - 1;
            }
            else 
            {
                cout << mid << endl;
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(int mid, vector<int>& nums)
    {
        long sum = 0;
        for(double num: nums)
        {
            sum += ceil(num/mid);
        }
        return sum <= limit;
    }
};
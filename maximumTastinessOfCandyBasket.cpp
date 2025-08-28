class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) 
    {
        sort(price.begin(), price.end());
        int left = 0;
        int right = 0;
        for(int num: price)
        {
            right = max(num, right);
        }
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(check(mid, price, k))
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
    bool check(int mid, vector<int>& price, int& k)
    {
        int cnt = 1;
        int lastIdx = 0;
        for(int i = 0; i < price.size(); i++)
        {
            if(abs(price[i] - price[lastIdx]) >= mid)
            {
                cnt++;
                lastIdx = i;
                if(cnt >= k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};//
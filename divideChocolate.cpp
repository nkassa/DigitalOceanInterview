class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) 
    {
        int left = 0;
        int right = 0;
        for(int num: sweetness)
        {
            right += num;
        }
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(check(mid, sweetness, k))
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
    bool check(int mid, vector<int>& sweetness, int& k)
    {
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < sweetness.size(); i++)
        {
            sum += sweetness[i];
            if(sum >= mid)
            {
                cnt++;
                sum = 0;
            }
        }
        return cnt >= k+1;
    }
};
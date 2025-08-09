class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = 0;
        int right = 0;
        for(int weight: weights)
        {
            left = max(weight, left);
            right += weight;
        }
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(helper(weights, days, mid))
            {
                right = mid-1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    bool helper(vector<int>& weights, int& days, int cap)
    {
        int count = 0;
        int weightSoFar = 0;
        for(int weight: weights)
        {
            if(weightSoFar + weight > cap)
            {
                count++;
                weightSoFar = 0;
            }
            weightSoFar += weight;
        }
        return count < days;
    }
};
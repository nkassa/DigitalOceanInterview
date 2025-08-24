class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int num: costs)
        {
            if(coins - num >= 0)
            {
                ans++;
                coins -= num;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
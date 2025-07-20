class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int ans = 0;
        for(vector<int> cost: costs)
        {
            ans += min(cost[0], cost[1]);
        }
        return ans;
    }
};
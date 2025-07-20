class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int ans = 0;
        int n = costs.size()/2;
        vector<int> diff;
        for(vector<int> cost: costs)
        {
            ans += cost[0];
            diff.push_back(cost[1] - cost[0]);
        }
        sort(diff.begin(), diff.end());
        for(int i = 0; i < n; i++)
        {
            ans += diff[i];
        }
        return ans;
    }
};
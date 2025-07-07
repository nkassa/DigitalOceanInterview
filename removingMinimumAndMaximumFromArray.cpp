class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        pair<int,int> mini = {INT_MAX, 0};
        pair<int,int> maxi = {INT_MIN, 0};;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mini.first > nums[i])
            {
                mini = {nums[i], i};
            }
            if(maxi.first < nums[i])
            {
                maxi = {nums[i], i};
            }
        }
        int left = max(maxi.second, mini.second)+1;
        int right = nums.size() - min(maxi.second, mini.second);
        int both = 0;
        if(maxi.second > mini.second)
        {
            both = (nums.size() - maxi.second) + (mini.second + 1);
        }
        else
        {
            both = (nums.size() - mini.second) + (maxi.second + 1);
        }
        int ans = min(right, left);
        ans = min(ans, both);
        return ans;
    }
};
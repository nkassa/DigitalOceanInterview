class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans(nums.size(),0);
        unordered_set<int> seen;
        int prod = 1;
        for(int i= 0; i < nums.size();i++)
        {
            if(nums[i] == 0)
            {
                seen.insert(i);
            }
            else
            {
                prod *= nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if( seen.find(i) == seen.end() && !seen.empty())
            {
                ans[i] = 0;
            }
            if(seen.find(i) != seen.end() && seen.size() == 1)
            {
                ans[i] = prod;
            }
            if(seen.find(i) != seen.end() && seen.size() > 1)
            {
                ans[i] = 0;
            }
            if(seen.empty())
            {
                ans[i] = prod / nums[i];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int left = 0;
        int ans = 0;
        int sum = 0;
        unordered_set<int> seen;
        for(int right = 0; right < nums.size(); right++)
        {
            while(seen.find(nums[right]) != seen.end())
            {
                seen.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            sum += nums[right];
            ans = max(ans, sum);
            seen.insert(nums[right]);
        }
        return ans;
    }
};
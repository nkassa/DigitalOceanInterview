class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int i = nums.size()-1;
        int cnt = 0;
        while(i >= 0 && cnt < 3)
        {
            ans *= nums[i];
            cnt++;
            i--;
        }
        return ans;
    }
};
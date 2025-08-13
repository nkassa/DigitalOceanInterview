class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        int i = n-1;
        int cnt = 0;
        while(i >= 0 && cnt < 3)
        {
            ans *= nums[i];
            cnt++;
            i--;
        }
        ans = max(ans, (nums[0]*nums[1]*nums[n-1]));
        return ans;
    }
};
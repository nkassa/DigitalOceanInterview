class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> post(n, 1);
        int prod = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            prod *= nums[i];
            pre[i] = prod;
        }
        prod = 1;
        for(int i = n-1; i >= 0; i--)
        {
            prod *= nums[i];
            post[i] = prod;
        }
        vector<int> ans(n);
        ans[0] = post[1];
        ans[n-1] = pre[n-2];
        for(int i = 1; i < ans.size()-1; i++)
        {
            ans[i] = pre[i-1] * post[i+1];
        }
        return ans;
    }
};
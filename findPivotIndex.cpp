class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        if(prefix[n-1] - prefix[0] == 0)
        {
            return 0;
        }
        for(int i = 1; i < n-1; i++)
        {
            int prev = prefix[i-1];
            int next = prefix[n-1] - prefix[i];
            if(prev == next)
            {
                return i;
            }
        }
        if(prefix[n-2] == 0)
        {
            return n-1;
        }
        return -1;
    }
};
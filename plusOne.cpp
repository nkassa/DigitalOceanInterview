class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        int carry = 0;
        vector<int> ans(n+1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            if(i == n-1)
            {
                sum += 1;
            }
            ans[i+1] = sum % 10;
            carry = sum / 10;
        }
        ans[0] = carry;
        if(ans[0] == 0)
        {
            vector<int> sol;
            for(int i = 1; i < ans.size(); i++)
            {
                sol.push_back(ans[i]);
            }
            return sol;
        }
        return ans;
    }
};
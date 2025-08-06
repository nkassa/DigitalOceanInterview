class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        int carry = 0;
        vector<int> ans(n+1, 0);
        int i = n-1;
        while(i >= 0 || carry > 0)
        {
            if(i >= 0)
            {
                int sum = digits[i] + carry;
                if(i == n-1)
                {
                    sum += 1;
                }
                ans[i+1] = sum % 10;
                carry = sum / 10;
            }
            else
            {
                ans[0] = carry;
                carry = 0;
            }
            i--;
        }
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
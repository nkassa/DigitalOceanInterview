class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n+m, 0);
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                int prod = (num1[i]-'0') * (num2[j]-'0');
                int sum = prod + res[i+j+1];
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        string ans = "";
        for(int digit: res)
        {
            if(!(ans.empty() && digit == 0))
            {
                ans += to_string(digit);
            }
        }
        if(ans.size() == 0)
        {
            return "0";
        }
        return ans;
    }
};
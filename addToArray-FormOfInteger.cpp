class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        int n = num.size();
        
        string str = to_string(k);
        vector<int> Karray;
        
        for(char c: str)
        {
            Karray.push_back(c-'0');
        }
        
        int size = 0;
        if(n+1 > Karray.size()+1)
        {
            size = n+1;
        }
        else
        {
            size = Karray.size()+1;
        }
        vector<int> ans(size, 0);
        
        int i = n-1;
        int j = Karray.size()-1;
        int carry = 0;
        int idx = ans.size()-1;
        
        while(i >= 0 || j >= 0 || carry > 0)
        {
            int sum = carry;
            if(i >= 0)
            {
                sum += num[i];
                i--;
            }
            if(j >= 0)
            {
                sum += Karray[j];
                j--;
            }
            ans[idx] = sum % 10;
            carry = sum / 10;
            idx--;
        }
        if(ans[0] == 0)
        {
            return vector<int>(ans.begin()+1, ans.end());
        }
        return ans;
    }
};
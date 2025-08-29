class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int maxi = 0;
        int n = 0;
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        for(auto [key,val]: count)
        {
            if(val >= maxi)
            {
                maxi = val;
                n = key;
            }
        }
        return n;
    }
};
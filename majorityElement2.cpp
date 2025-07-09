class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> count;
        for(int num:nums)
        {
            count[num]++;
        }
        int x = nums.size()/3;
        vector<int> ans;
        for(auto [key,value]: count)
        {
            if(value > x)
            {
                ans.push_back(key);
            }
        }
        return ans;
    }
};
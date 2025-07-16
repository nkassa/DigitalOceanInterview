class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> list(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            list[nums[i]]++;
        }
        vector<int> ans;
        for(int i = 1; i < nums.size()+1; i++)
        {
            if(list[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
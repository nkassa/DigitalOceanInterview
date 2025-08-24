class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        sort(nums.begin(), nums.end());
        vector<int> prefix;
        prefix.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            prefix.push_back(prefix.back() + nums[i]);
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++)
        {
            int left = 0; 
            int right = prefix.size()-1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(prefix[mid] < queries[i])
                {
                    left = mid + 1;
                }
                else if(prefix[mid] == queries[i])
                {
                    right = mid;
                    break;
                }
                else
                {
                    right = mid - 1;
                }
            }
            ans.push_back(right+1);
        }
        return ans;
    }
};
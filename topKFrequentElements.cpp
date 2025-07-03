class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> heap;
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        for(auto [key,val]: count)
        {
            heap.push({val, key});
        }
        int i = 0;
        vector<int> ans = {};
        while(!heap.empty())
        {
            if(i == k)
            {
                return ans;
            }
            ans.push_back(heap.top().second);
            heap.pop();
            i++;
        }
        return ans;
    }
};
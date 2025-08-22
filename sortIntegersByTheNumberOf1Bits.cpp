class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        priority_queue<pair<int,int>> heap;
        for(int i = 0; i < arr.size(); i++)
        {
            int cnt = __builtin_popcount(arr[i]);
            heap.push({cnt, arr[i]});
        }
        vector<int> ans(heap.size());
        for(int i = heap.size()-1; i >= 0; i--)
        {
            ans[i] = heap.top().second;
            heap.pop();
        }
        return ans;
    }
};
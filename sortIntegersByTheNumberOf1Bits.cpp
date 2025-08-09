class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(int num: arr)
        {
            int count = __builtin_popcount(num);
            heap.push({count, num});
        }
        vector<int> ans;
        while(!heap.empty())
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};//
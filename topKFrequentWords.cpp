class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> count;
        for(string word: words)
        {
            count[word]++;
        }
        priority_queue<pair<int,string>> heap;
        for(auto [key,val]: count)
        {
            heap.push({-1*val, key});
        }
        while(heap.size() > k)
        {
            heap.pop();
        }
        vector<string> ans(k);
        int i = k-1;
        while(!heap.empty())
        {
            ans[i] = heap.top().second;
            i--;
            heap.pop();
        }
        return ans;
    }
};
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int> count;
        unordered_set<int> seen;
        for(int num: arr)
        {
            count[num]++;
        }
        for(auto [kay, val]: count)
        {
            if(seen.find(val) != seen.end())
            {
                return false;
            }
            seen.insert(val);
        }
        return true;
    }
};
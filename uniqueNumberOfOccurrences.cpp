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
        for(auto [key,val]: count)
        {
            seen.insert(val);
        }
        return seen.size() == count.size();
    }
};
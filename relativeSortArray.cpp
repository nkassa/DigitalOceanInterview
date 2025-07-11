class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map<int,int> count;
        for(int num: arr1)
        {
            count[num]++;
        }
        vector<int> ans(arr1.size());
        int i = 0;
        for(int num: arr2)
        {
            int size = count[num];
            for(int j = 0; j < size; j++)
            {
                ans[i] = num;
                i++;
            }
            count.erase(num);
        }
        for(auto [key,val]: count)
        {
            for(int j = 0; j < val; j++)
            {
                ans[i] = key;
                i++;
            }
        }
        int idx = arr1.size()-arr2.size();
        sort(ans.begin() + idx, ans.end());
        return ans;
    }
};
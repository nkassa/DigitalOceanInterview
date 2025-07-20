class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int n = arr.size()/4;
        unordered_map<int,int> count;
        for(int num: arr)
        {
            count[num]++;
            if(count[num] > n)
            {
                return num;
            }
        }
        return 0;
    }
};
class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        if(arr.size() < 3)
        {
            return false;
        }
        int max = 0;
        int idx = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(max < arr[i])
            {
                max = arr[i];
                idx = i;
            }
        }
        if(idx == 0 || idx == arr.size()-1)
        {
            return false;
        }
        for(int i = 1; i < idx-1; i++)
        {
            if(arr[i-1] >= arr[i])
            {
                return false;
            }
        }
        for(int i = idx; i < arr.size()-1; i++)
        {
            if(arr[i] <= arr[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
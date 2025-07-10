class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        vector<int> list;
        list.push_back(0);
        int ans = 0;
        for(int i = 0; i < seats.size(); i++)
        {
            if(seats[i] == 1)
            {
                list.push_back(i);
            }
        }
        list.push_back(seats.size()-1);
        for(int i = 1; i < list.size(); i++)
        {
            ans = max(ans, (list[i] - list[i-1])/2);
        }
        return ans;
    }
};
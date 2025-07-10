class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        vector<int> list;
        int ans = 0;
        for(int i = 0; i < seats.size(); i++)
        {
            if(seats[i] == 1)
            {
                list.push_back(i);
            }
        }
        for(int i = 1; i < list.size(); i++)
        {
            ans = max(ans, (list[i] - list[i-1]+1)/2);
        }
        int x = seats.size()-1;
        int y = list.size()-1;
        ans = max(ans, list[0] - 0);
        ans = max(ans, x - list[y]);
        return ans;
    }
};
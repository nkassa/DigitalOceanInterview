class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        vector<int> list;
        for(int i = 0; i < seats.size(); i++)
        {
            if(seats[i] == 1)
            {
                list.push_back(i);
            }
        }
        int left = 0;
        int right = seats.size()-1;
        int ans = list[left]-0;
        ans = max(ans, right - list[list.size()-1]);
        for(int i = 1; i < list.size(); i++)
        {
            ans = max(ans, (list[i] - list[i-1])/2);
        }
        return ans;
    }
};
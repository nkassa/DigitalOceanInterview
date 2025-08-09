class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        unordered_map<int,int> count;
        for(int card: deck)
        {
            count[card]++;
        }
        int num = 0;
        for(auto [key, val]: count)
        {
            num = gcd(val, num);
            if(num == 1)
            {
                return false;
            }
        }
        return num > 1;
    }
};
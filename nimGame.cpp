class Solution {
public:
    bool canWinNim(int n) 
    {
        return n < 3 || n % 3 == 0;
    }
};
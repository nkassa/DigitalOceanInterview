class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int size = flowerbed.size();
        for(int i = 0; i < size; i++)
        {
            if(flowerbed[i] == 0)
            {
                int left;
                int right;
                if(i == 0)
                {
                    left = 0;
                }
                else
                {
                    left = flowerbed[i-1];
                }
                
                if(i == size-1)
                {
                    right = 0;
                }
                else
                {
                    right = flowerbed[i+1];
                }
                if(left == 0 && right == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                if(n <= 0)
                {
                    break; 
                }
            }
        }
        return n <= 0;
    }
};
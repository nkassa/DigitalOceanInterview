class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left < right)
        {
            int diff = right - left;
            ans = max(ans, diff * min(height[left], height[right]));
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};

// two pointer 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> heap;
        for(int num:nums)
        {
            heap.push(num);
        }
        int i = 1;
        while(!heap.empty())
        {
            if(i == k)
            {
                return heap.top();
            }
            heap.pop();
            i++;
        }
        return -1;
    }
};
class SmallestInfiniteSet 
{
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<int> list;
    SmallestInfiniteSet() 
    {
        int n = 1000;
        list = vector<int>(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            heap.push(i);
            list[i] = 1;
        }
    }
    
    int popSmallest() 
    {
        int top = heap.top();
        list[top] = 0;
        heap.pop();
        return top;
    }
    
    void addBack(int num) 
    {
        if(list[num] == 0)
        {
            heap.push(num);
            list[num] = 1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
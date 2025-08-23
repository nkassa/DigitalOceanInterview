class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    SeatManager(int n) 
    {
        for(int i = 1; i <= n; i++)
        {
            heap.push(i);
        }
    }
    
    int reserve() 
    {
        int result = heap.top();
        heap.pop();
        return result;
    }
    
    void unreserve(int seatNumber) 
    {
        heap.push(seatNumber);
    }
};


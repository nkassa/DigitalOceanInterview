class MyQueue {
public:
    stack<int> list;
    stack<int> listTwo;
    MyQueue() {
    }
    
    void push(int x) 
    {
        list.push(x);
    }
    
    int pop() 
    {
        peek();
        int i = listTwo.top();
        listTwo.pop();
        return i;
    }
    
    int peek() 
    {
        if(listTwo.empty())
        {
            while(!list.empty())
            {
                int top = list.top();
                list.pop();
                listTwo.push(top);
            }
        }
        return listTwo.top();
    }
    
    bool empty() 
    {
        return listTwo.size() == 0 && list.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
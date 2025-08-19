class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        for (int num : asteroids) 
        {
            bool destroyed = false;
            // Only possible collision: current going left (num < 0), stack top going right (st.top() > 0)
            while (!st.empty() && num < 0 && st.top() > 0) 
            {
                if (abs(st.top()) < abs(num)) 
                {
                    st.pop(); // right-moving asteroid is smaller → destroyed
                    continue; // keep checking with next
                } 
                else if (abs(st.top()) == abs(num)) 
                {
                    st.pop(); // both destroyed
                }
                destroyed = true; // current asteroid is destroyed
                break;
            }
            if (!destroyed) 
            {
                st.push(num);
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) 
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

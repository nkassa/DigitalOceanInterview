class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, vector<int>> classes;
        vector<int> indegree(numCourses, 0);
        for(vector<int> pre: prerequisites)
        {
            classes[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> queue;
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }
        int cnt = 0;
        while(!queue.empty())
        {
            int course = queue.front();
            queue.pop();
            cnt++;
            for(int num: classes[course])
            {
                indegree[num]--;
                if(indegree[num] == 0)
                {
                    queue.push(num);
                }
            }
        }
        return cnt == numCourses;
    }
};
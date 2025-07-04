class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> count;
        unordered_set<string> list;
        for(string word: wordList)
        {
            list.insert(word);
        }
        count.insert(beginWord);
        queue<pair<int,string>> queue;
        queue.push({1, beginWord});
        while(!queue.empty())
        {
            string curr = queue.front().second;
            int steps = queue.front().first;
            if(curr == endWord)
            {
                return steps;
            }
            queue.pop();
            for(char c: "abcdefghijklmnopqrstuvwxyz")
            {
                string neighbor = curr;
                for(int i = 0; i < neighbor.size(); i++)
                {
                    neighbor[i] = c;
                    if(list.find(neighbor) != list.end())
                    {
                        queue.push({steps+1, neighbor});
                    }
                }
            }
        } 
        return 0;
    }
};
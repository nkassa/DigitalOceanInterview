class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> count;
        unordered_set<string> list;
        queue<pair<int,string>> queue;
        for(string word: wordList)
        {
            list.insert(word);
        }
        count.insert(beginWord);
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
                for(int i = 0; i < curr.size(); i++)
                {
                    string neighbor = curr;
                    neighbor[i] = c;
                    if(list.find(neighbor) != list.end() && count.find(neighbor) == count.end())
                    {
                        queue.push({steps+1, neighbor});
                        count.insert(neighbor);
                    }
                }
            }
        } 
        return 0;
    }
};
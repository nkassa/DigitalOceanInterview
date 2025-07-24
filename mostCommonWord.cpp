class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        unordered_map<string, int> count;
        unordered_set<string> ban;
        for(string str: banned)
        {
            ban.insert(str);
        }
        string temp = "";
        for(int i = 0; i < paragraph.size(); i++)
        {
            if(isalpha(paragraph[i]))
            {
                temp += tolower(paragraph[i]);
            }
            if((!isalpha(paragraph[i]) || i == paragraph.size()-1) && temp.size() != 0)
            {
                count[temp]++;
                temp = "";
            }
        }
        priority_queue<pair<int,string>> heap;
        for(auto [key,value]: count)
        {
            heap.push({value, key});
        }
        while(!heap.empty())
        {
            if(ban.find(heap.top().second) == ban.end())
            {
                return heap.top().second;
            }
            heap.pop();
        }
        return "";
    }
};
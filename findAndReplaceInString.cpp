class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) 
    {
        vector<pair<int, int>> ops; 
        int k = indices.size();
        
        for (int i = 0; i < k; i++) {
            ops.push_back({indices[i], i});
        }
        
        sort(ops.begin(), ops.end());
        
        string result;
        int i = 0; // pointer in s
        int opIdx = 0; // pointer in ops
        
        while (i < s.size()) {
            if (opIdx < k && i == ops[opIdx].first) {
                int idx = ops[opIdx].second;
                string& src = sources[idx];
                string& tgt = targets[idx];
                
                if (s.compare(i, src.size(), src) == 0) {
                    result += tgt;
                    i += src.size();
                } else {
                    result += s[i];
                    i++;
                }
                opIdx++;
            } else {
                result += s[i];
                i++;
            }
        }
        
        return result;
    }
};
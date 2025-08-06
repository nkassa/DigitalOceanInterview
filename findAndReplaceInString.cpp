class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<int> match(n, -1); 
        
        for (int i = 0; i < indices.size(); i++) {
            if (s.compare(indices[i], sources[i].size(), sources[i]) == 0) {
                match[indices[i]] = i; 
            }
        }
        
        string result;
        int i = 0;
        while (i < n) {
            if (match[i] != -1) {
                result += targets[match[i]];
                i += sources[match[i]].size();
            } else {
                result += s[i];
                i++;
            }
        }
        
        return result;
    }
};
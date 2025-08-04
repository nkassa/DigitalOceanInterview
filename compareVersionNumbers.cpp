class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int i = 0;
        int j = 0;
        int n = version1.size();
        int m = version2.size();
        while(i < n || j < m)
        {
            long int val = 0;
            while(i < n && version1[i] != '.')
            {
                val =  (val * 10) +  version1[i] - '0';
                i++;
            }
            long int val2 = 0;
            while(j < m && version2[j] != '.')
            {
                val2 =  (val2 * 10) +  version2[j] - '0';
                j++;
            }

            if(val < val2)
            {
                return -1;
            }
            if(val > val2)
            {
                return 1;
            }
            j++;
            i++;
        }
        return 0;
    }
};
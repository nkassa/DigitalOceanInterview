class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        vector<int> count(60, 0); // count of each remainder
        int ans = 0;

        for (int t : time) {
            int rem = t % 60;
            int complement = (60 - rem) % 60; // handles rem = 0 case
            ans += count[complement]; // add how many we can pair with
            count[rem]++; // store remainder for future matches
        }
        return ans;
    }
};
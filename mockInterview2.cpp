#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

time_t helptime(string str)
{
    tm tms = {};
    istringstream ss(str);
    ss >> std::get_time(&tms, "%Y-%m-%d %H:%M:%S");  
    std::time_t time = mktime(&tms);
    return time;
}
double dateTime(time_t str, time_t strs)
{
    return difftime(str, strs)/3600;
}
vector<string> helper(vector<pair<string, string>> list)
{
    vector<string> ans;
    unordered_map<string, vector<string>> count;
    for(int i= 0; i< list.size(); i++)
    {
   //     cout << list[i].first << " " << list[i].second << endl;
        count[list[i].first].push_back(list[i].second);
    }
    for(auto [key,val]: count)
    {
        vector<time_t> times;
        for(string str: val)
        {
           // cout<< str<<endl;
            times.push_back(helptime(str));
        }
        sort(times.begin(), times.end());
        for(int i = 1; i < times.size(); i++)
        {
            double diff = dateTime(times[i], times[i-1]);
            if (diff <= 48)
            {
                cout << key << endl;
                ans.push_back(key);
                break;
            }
        }
    }
    return ans;
}

int main()
{
    vector<pair<string,string>> list = {{"90", "2025-07-01 23:00:00"},
                                       {"90", "2025-06-30 14:00:00"},
                                       {"100", "2025-06-30 22:00:00"},
                                       {"80", "2025-05-30 15:00:00"},
                                        {"80", "2025-07-01 20:00:00"}};
    vector<string> ans = helper(list);
    return 0;
}

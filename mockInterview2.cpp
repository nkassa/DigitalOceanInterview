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
vector<string> helper(vector<pair<string, string>> list)
{
    vector<string> ans;
    unordered_map<string, vector<string>> count;
    for(int i= 0; i < list.size(); i++)
    {
        count[list[i].first].push_back(list[i].second);
    }
    for(auto [key,val]: count)
    {
        vector<string> times;
        for(string str: val)
        {
            times.push_back(str);
        }
        sort(times.begin(), times.end());
        for(int i = 1; i < times.size(); i++)
        {
            double diff = difftime(helptime(times[i]), helptime(times[i-1]))/3600;
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
                                       {"80", "2025-06-30 14:00:00"},
                                       {"70", "2025-06-30 22:00:00"},
                                       {"60", "2025-05-30 15:00:00"},
                                        {"50", "2025-07-01 20:00:00"}};
    vector<string> ans = helper(list);
    return 0;
}
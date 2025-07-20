#include <iostream>
#include <unordered_set>
using namespace std;
string helper(string strOne, string strTwo)
{
    if(strOne == strTwo)
    {
        return strOne;
    }
    if(strTwo.size() == 0 || strOne.size() == 0)
    {
        return "";
    }
    string ans = "";
    unordered_set<char> seen(strTwo.begin(), strTwo.end());
    for(char c: strOne)
    {
        if(seen.find(c) == seen.end())
        {
            return ans;
        }
        else
        {
            ans += c;
        }
    }
    return ans;
}
int main()
{
    string one = "substring";
    string two = "submarine";
    cout << helper(one,two) << endl;
    return 0;
}
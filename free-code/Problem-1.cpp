#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char,bool> sheet;
    string s = "hellodworld";
    string ans = "";
    for(int i = 0;i < s.size();i++)
    {
        if(!sheet[s[i]])
        {
            ans = s.substr(0,i+1);
            sheet[s[i]] = 1;
        }
    }
    cout<<ans;
    return 0;
}
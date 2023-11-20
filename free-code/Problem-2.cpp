#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s = "abbc";
    string ans = "";
    int cnt = 0;
    char curr = '#';
    int i = 0;
    while(i<s.size())
    {
        if(curr!=s[i]&&curr!='#')
        {
            if(cnt>1)
            {
                ans+=curr;
                ans+=to_string(cnt);
            }
            else
            {
                ans+=curr;
            }
            curr='#';
            cnt=0;
            continue;
        }
        if(curr == '#'||curr==s[i])
        {
            curr=s[i];
            cnt++;
        }
        i++;
    }
    if(cnt>1)
    {
        ans+=curr;
        ans+=to_string(cnt);
    }
    else
    {
        ans+=curr;
    }
    cout<<ans;
    return 0;
}
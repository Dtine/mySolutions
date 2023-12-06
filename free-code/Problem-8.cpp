#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = 15;
    unordered_map<int,int> prefix;
    prefix[0] = arr[0];
    for(int i = 1; i<arr.size();i++)
    {
        prefix[i]=arr[i]+prefix[i-1];
    }
    unordered_map<int,int> mp;
    mp[0] = 1;
    int ans = 0;
    for(int i = 0;i<prefix.size();i++)
    {
        if(mp.find(prefix[i]-num)!=mp.end())
        {
            ans+=mp[prefix[i]-num];
        }
        mp[prefix[i]]++;
    }
    cout<<ans;
}
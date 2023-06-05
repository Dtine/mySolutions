#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,int> mp;
    for(int i=1;i<=n;i++)
    {
        string to=to_string(i);
        mp[to]=1;
    }
    string wtf;
    cin>>wtf;
    int cnt=0;
    for(auto&i:mp)
    {
        cnt++;
        if(i.first==wtf)
        {
            break;
        }
    }
    cout<<cnt;
    return 0;
}

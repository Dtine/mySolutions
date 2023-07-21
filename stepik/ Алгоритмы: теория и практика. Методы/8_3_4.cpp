#include <bits/stdc++.h>

using namespace std;
int func(string& a,string& b)
{
    int dp[a.size()+1][b.size()+1];
    for(int i=0;i<a.size()+1;i++)
    {
        dp[i][0]=i;
    }
    for(int j=0;j<b.size()+1;j++)
    {
        dp[0][j]=j;
    }
    for(int i=1;i<a.size()+1;i++)
    {
        for(int j=1;j<b.size()+1;j++)
        {
            
            dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+!(a[i-1]==b[j-1])));
        }
    }
    return dp[a.size()][b.size()];
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<min(func(a,b),func(b,a));
    return 0;
}

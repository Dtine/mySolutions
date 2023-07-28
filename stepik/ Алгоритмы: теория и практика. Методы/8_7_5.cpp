#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl<<1;
        return 0;
    }
    vector<int> dp(n*3+1,INT_MAX);
    vector<int> p(n*3+1,-1);
    dp[1]=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i+1]>dp[i]+1)
        {
            dp[i+1]=dp[i]+1;
            p[i+1]=i;
        }
        if(dp[i*2]>dp[i]+1)
        {
            dp[i*2]=dp[i]+1;
            p[i*2]=i;
        }
        if(dp[i*3]>dp[i]+1)
        {
            dp[i*3]=dp[i]+1;
            p[i*3]=i;
        }
    }
    vector<int> ans;
    ans.push_back(n);
    int next=dp[n]-1;
    cout<<dp[n]<<endl;
    while(n!=1)
    {
        ans.push_back(p[n]);
        n=p[n];
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
}



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)
    {
        graph[i][i]=0;
    }
    while(m--)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        from--,to--;
        graph[from][to]=cost;
        graph[to][from]=cost;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][k]<INT_MAX&&graph[k][j]<INT_MAX)
                {
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    int num=0;
    int cur=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int max=*max_element(graph[i].begin(),graph[i].end());
        if(num==0||cur>max)
        {
            cur=max;
            num=i+1;
        }
    }
    cout<<num;
}

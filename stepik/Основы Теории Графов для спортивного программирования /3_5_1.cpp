#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,start,end;
    cin>>n>>start>>end;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
            graph[i][j]=(graph[i][j]==-1?INT_MAX:graph[i][j]);
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][k]<INT_MAX&&graph[k][j]<INT_MAX)
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    cout<<(graph[start-1][end-1]==INT_MAX?-1:graph[start-1][end-1]);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> graph(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>graph[i][j];
        }
    }
    int starts;
    cin>>starts;
    pair<int,int> ans;
    ans.first=-1;
    ans.second=INT_MAX;
    for(int i=0;i<starts;i++)
    {
        pair<int,int> start;
        cin>>start.first>>start.second;
        start.first--,start.second--;
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<int,int>> bfs;
        bfs.push(start);
        while(!bfs.empty())
        {
            auto from=bfs.front();
            bfs.pop();
            if(graph[from.first][from.second]=='*')
            {
                if(dist[from.first][from.second]<ans.second)
                {
                    ans.first=i+1;
                    ans.second=dist[from.first][from.second];
                }
            }
            if(from.first+1<n&&graph[from.first+1][from.second]!='1'&&dist[from.first+1][from.second]==0)
            {
                auto next=from;
                next.first++;
                bfs.push(next);
                dist[next.first][next.second]=dist[from.first][from.second]+1;
            }
            if(from.first-1>=0&&graph[from.first-1][from.second]!='1'&&dist[from.first-1][from.second]==0)
            {
                auto next=from;
                next.first--;
                bfs.push(next);
                dist[next.first][next.second]=dist[from.first][from.second]+1;
            }
            if(from.second+1<m&&graph[from.first][from.second+1]!='1'&&dist[from.first][from.second+1]==0)
            {
                auto next=from;
                next.second++;
                bfs.push(next);
                dist[next.first][next.second]=dist[from.first][from.second]+1;
            }
            if(from.second-1>=0&&graph[from.first][from.second-1]!='1'&&dist[from.first][from.second-1]==0)
            {
                auto next=from;
                next.second--;
                bfs.push(next);
                dist[next.first][next.second]=dist[from.first][from.second]+1;
            }
        }
    }
    cout<<ans.first;
    return 0;
}

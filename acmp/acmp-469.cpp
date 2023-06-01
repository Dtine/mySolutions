#include <bits/stdc++.h>

using namespace std;
#define unsigned long long long long

pair<int,int> to_pair(long long big)
{
    pair<int,int> pr;
    pr.first=big>>32;
    pr.second=big-((big>>32)<<32);
    return pr;
}

long long from_pair(pair<int,int> pr)
{
    long long big=pr.first;
    big=(big<<32)+pr.second;
    return big;
}
int main(){
    
    int n,m;
    cin>>n>>m;
    unordered_map<long long,vector<pair<int,long long>>> graph;
    unordered_map<long long,int> distances;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            long long ver=from_pair({i,j});
            cin>>distances[ver];
        }
    }
    graph[0].push_back({distances[from_pair({1,1})],from_pair({1,1})});
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            long long from=from_pair({i,j});
            if(i-1>=1)
            {
                long long to=from_pair({i-1,j});
                graph[from].push_back({distances[to],to});
            }
            if(i+1<=n)
            {
                long long to=from_pair({i+1,j});
                graph[from].push_back({distances[to],to});
            }
            if(j-1>=1)
            {
                long long to=from_pair({i,j-1});
                graph[from].push_back({distances[to],to});
            }
            if(j+1<=m)
            {
                long long to=from_pair({i,j+1});
                graph[from].push_back({distances[to],to});
            }
        }
    }
    vector<vector<int>> dist(n+1,vector<int>(m+1,INT_MAX));
    dist[0][0]=0;
    priority_queue<pair<int,long long>,vector<pair<int,long long>>,greater<pair<int,long long>>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
       long long ver=pq.top().second;
       pair<int,int> pair_ver=to_pair(pq.top().second);
       pq.pop();
       for(auto&edge:graph[ver])
       {
           int d=edge.first;
           pair<int,int> next=to_pair(edge.second);
           if(dist[pair_ver.first][pair_ver.second]+d<dist[next.first][next.second])
           {
               dist[next.first][next.second]=dist[pair_ver.first][pair_ver.second]+d;
               pq.push({dist[next.first][next.second],edge.second});
           }
       }
    }
    cout<<dist[n][m];
    return 0;
}






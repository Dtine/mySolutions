#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<int> q;
    int count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int k;
            cin>>k;
            if(k==1)
            {
                count++;
                q.push(i+1);
                q.push(j+1);
            }
        }
    cout<<n<<" "<<count<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
class Node
{
    public:
    char value;
    Node* left;
    Node* right;
    Node():
    left(nullptr),right(nullptr),value('0')
    {}
    Node(char value):
    left(nullptr),right(nullptr),value(value)
    {}
    Node(Node* left,Node* right):
    left(left),right(right),value('0')
    {}
};


map<char,string> table;


void solve(Node* root,string s)
{
    if(root->left!=nullptr&&root->right!=nullptr)
    {
        solve(root->left,s+"0");
        solve(root->right,s+"1");
    }
    else
    {
        table[root->value]=s;
    }
    
}

int main()
{
    unordered_map<char,int> cnt;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        cnt[s[i]]++;
    }
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> q;
    for(auto i=cnt.begin();i!=cnt.end();i++)
    {
        Node* curr = new Node(i->first);
        q.push({i->second,curr});
    }
    while(q.size()!=1)
    {
        Node* left=q.top().second;
        int left_freq=q.top().first;
        q.pop();
        Node* right=q.top().second;
        int right_freq=q.top().first;
        q.pop();
        int sum_freq=left_freq+right_freq;
        if(left_freq>right_freq)
        {
            swap(left_freq,right_freq);
            swap(right,left);
        }
        Node* next=new Node(left,right);
        q.push({sum_freq,next});
    }
    solve(q.top().second,"");
    string ans="";
    if(cnt.size()==1)
    {
        table[s[0]]="0";
    }
    for(int i=0;i<s.size();i++)
    {
        ans+=table[s[i]];
    }
    cout<<table.size()<<" "<<ans.size()<<endl;
    for(auto i=table.begin();i!=table.end();i++)
    {
        cout<<i->first<<": "<<i->second<<endl;
    }
    cout<<ans;
    return 0;
}

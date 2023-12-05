#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int a(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] != 0&&i>0)
                {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        sort(matrix[i].begin(),matrix[i].end(),greater());
        auto k = matrix[i];
        for(int j = 0;j<m;j++)
        {
            ans=max(ans,k[j]*(j+1));
        }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> piles={{0,1,0},{1,1,1},{1,1,0}};
    cout<<s.a(piles);

    return 0;
}
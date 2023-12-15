#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = 0;
        vector<vector<int>> matrix(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=arr[i][j]-'0';

                if(i==0||arr[i][j]=='0')continue;

                matrix[i][j]+=matrix[i-1][j];
            }
        }

        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                int fp = j;
                int sp = j;
                int height = matrix[i][sp];
                while(sp>=0 && matrix[i][sp]!=0 && fp-sp+1<=height)
                {
                    ans=max(ans,fp-sp+1);
                    height=min(height,matrix[i][sp]);
                    sp--;
                }
                j=sp;
            }
        }
        return ans*ans;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> a = {{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','0','0','0'},{'1','1','1','1','1'},{'1','1','1','1','1'}};
    cout<<s.maximalSquare(a);

    return 0;
}
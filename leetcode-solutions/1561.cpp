#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans = 0;
        int last_index = piles.size()-1;
        int bob_index = 0;
        while(bob_index!=last_index)
        {
            int alice = piles[last_index];
            int me = piles[last_index-1];
            int bob = piles[bob_index];
            last_index-=2;
            bob_index++;
            ans+=me;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> piles={2,4,1,2,7,8};
    cout<<s.maxCoins(piles);

    return 0;
}
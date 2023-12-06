#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr={1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int ans = 0;
    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i] == 1)
        {
            bool skip_first = true;
            int j = i+1;
            while(j<arr.size())
            {
                if(arr[j] == 0)
                {
                    if(skip_first)
                    {
                        skip_first = false;
                    }
                    else
                    {
                        break;
                    }
                }
                j++;
            }
            ans = max(ans,j-i-1);
            if(skip_first)
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
}
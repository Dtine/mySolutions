#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    vector<int> nums = {56, 23, 7, 41, 95, 14, 62, 30, 84, 2};
    int first = INT_MIN;
    int second = INT_MIN;
    for(int i = 0;i<nums.size();i++)
    {
        if(nums[i]>=first)
        {
            second = first;
            first = nums[i];
        }
        else if(nums[i]>second)
        {
            second = nums[i];
        }
    }
    cout<<second;
    return 0;
}
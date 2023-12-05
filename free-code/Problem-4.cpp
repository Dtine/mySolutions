#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    string str = "ab", needed = "abc";
    //cin>>str>>needed;
    unordered_map<char,int> letters;
    for(auto&i:needed)
    {
        letters[i]++;
    }
    int ans = 0;
    for(int i = 0;i < str.size()-needed.size()+1;i++)
    {
        if(letters[str[i]]>0)
        {
            auto curr_substr_letters = letters;
            
            int j = i;
            bool is_valid = true;
            while(j<needed.size()+i)
            {
                if(curr_substr_letters[str[j]]>0)
                {
                    curr_substr_letters[str[j]]--;
                }
                else
                {
                    is_valid = false;
                    break;
                }
                j++;
            }
            if(is_valid)
            {
                ans++;
            }
        }    
    }
    cout<<ans;

    return 0;
}
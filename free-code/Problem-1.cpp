#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s = "hellheodwrorld";
    string alph = "";
    string ans = "";

    //составление алфавита из строки s;

    for(int i = 0;i<s.size();i++)
    {
        if(find(alph.begin(),alph.end(),s[i])==alph.end())
        {
            alph+=s[i];
        }
    }

    //поиск ответа

    size_t sz=INT_MAX;
    int first = 0;
    int second = 0;
    int i = 0;
    int j = 0;
    while(j<s.size())
    {
        string temp = s.substr(i,j-i+1);
        if(j-i+1 > 1 && temp[0] == temp[temp.size()-1]||temp[0]==temp[1])
        {
            i++;
            continue;
        }
        if(temp.size()<alph.size())
        {
            j++;
            continue;
        }
        int ii = 0;
        while(ii<alph.size())
        {
            bool ok = false;
            for(int jj = 0;jj<temp.size();jj++)
            {
                if(alph[ii]==temp[jj])
                {
                    ok=true;
                    break;
                }
            }
            if(!ok)break;
            ii++;
        }
        if(ii==alph.size())
        {
            if(sz>j-i+1)
            {
                first=i;
                second=j;
                sz=j-i+1;
            }
        }
        j++;
    }
    
    cout<<first<<" "<<second<<" "<<s.substr(first,second-first+1);
    return 0;
}
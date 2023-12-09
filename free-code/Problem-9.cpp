#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template<typename T>
class str_queue{

    private:
    vector<T> __vec;
    size_t __size;
    size_t __curr_size;

    public:
    str_queue()
    {
        cout<<"Type structure size!"<<endl;
        exit(0);
    }
    str_queue(size_t n)
    {
        this->__size = n;
        __curr_size = 0;
    }
    void add(int num)
    {
        if(__size != __curr_size)
        {
            if(find(__vec.begin(),__vec.end(),num) == __vec.end())
            {
                __vec.push_back(num);
                __curr_size++;
            }
            else
            {
                size_t __pos = find(__vec.begin(),__vec.end(),num) - __vec.begin();
                __vec.erase(__vec.begin() + __pos);
                __vec.push_back(num);
            }
        }
        else
        {
            if(find(__vec.begin(),__vec.end(),num) == __vec.end())
            {
                __vec.pop_back();
                __vec.push_back(num);
            }
            else
            {
                size_t __pos = find(__vec.begin(),__vec.end(),num) - __vec.begin();
                __vec.erase(__vec.begin() + __pos);
                __vec.pop_back();
                __vec.push_back(num);
            }
        }
    }
    T& get()
    {
        if(__curr_size == 0)
        {
            cout<<"No elements to get()!"<<endl;
            exit(0);
        }
        else
        {
            return __vec.front();
        }
    }
    void pop()
    {
        if(__curr_size == 0)
        {
            cout<<"No element to pop()!"<<endl;
            exit(0);
        }
        else
        {
            __vec.erase(__vec.begin());
            __curr_size--;
        }
    }
};

int main()
{
    str_queue<int> q(10);
    q.add(1);
    q.add(2);
    cout<<q.get()<<endl;
    q.add(1);
    cout<<q.get()<<endl;
    return 0;
}
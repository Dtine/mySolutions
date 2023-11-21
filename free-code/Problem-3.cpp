#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;


template<typename Key,typename Name>
class S
{
    pair<Key,Name> values;
    S* next;

    S()
    {
        values.first = NULL;
        values.second = NULL;
        next = nullptr;
    }
    
    S(Key key,Name name)
    {
        values.first = key;
        values.second = name;
        next = nullptr;
    }
    S(pair<Key,Name> values, S* next)
    {
        this->values=values;
        this->next=next;
    }
};


template<typename Key,typename Name>
class hash_map
{
    private:
    vector<S<Key,Name>*> buckets;
    size_t bucket_size;
    size_t num_of_elements;
    
    void increase_size()
    {
        vector<S<Key,Name>*> temp(bucket_size*2,nullptr);
        bucket_size*=2;

        for(int i = 0;i<bucket_size/2;i++)
        {
            connector(buckets[i],temp);    
        }
        
        buckets=temp;
    }

    void connector(S<Key,Name>* List,vector<S<Key,Name>*>& temp)
    {
        while(List!=nullptr)
        {
            size_t new_index = hash<Key>{}(List->first.first);
            new_index%=bucket_size;
            if(temp[new_index] != nullptr)
            {
                temp[new_index] = List;
            }
            else
            {
                S<Key,Name>* head = temp[new_index];
                while(temp[new_index]->next!=nullptr)
                {
                    temp[new_index]=temp[new_index]->next;
                }
                temp[new_index]->next=List;
                List=List->next;
                temp[new_index]->next->next=nullptr;
                temp[new_index]=head;
            }
        }
    }

    public:
    hash_map()
    {
        buckets.resize(5,nullptr);
        bucket_size = 5;
        num_of_elements = 0;
    } 
    /* 
    Name& operator[](const Key key)
    {  
        
       ...    still in progress

    }
    */ 
};

int main()
{
    hash_map<int,int> mp;




    return 0;
}
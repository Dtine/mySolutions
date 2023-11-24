#include <iostream>
#include <vector>
#include <functional>

using namespace std;


template<typename Key = int,typename Name = int>
class S
{   
    public:
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
        bucket_size*=2;
        vector<S<Key,Name>*> temp(bucket_size,nullptr);

        for(int i = 0;i<bucket_size/2;i++)
        {
            if(buckets[i]!=nullptr)
                connector(buckets[i],temp);    
        }
        
        buckets=temp;
    }

    void connector(S<Key,Name>* List,vector<S<Key,Name>*>& temp)
    {
        while(List!=nullptr)
        {
            size_t new_index = hash<Key>{}(List->values.first);
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
    void set(Key key,Name name)
    {
        if(bucket_size == num_of_elements)
        {
            increase_size();
        }
        size_t index = hash<Key>{}(key);
        index%=bucket_size;
        if(buckets[index] == nullptr)
        {
            buckets[index] = new S(key,name);
            num_of_elements++;
            return;
        }
        S<Key,Name>* head = buckets[index];
        while(buckets[index]->next != nullptr)
        {
            if(buckets[index]->values.first == key)
            {
                break;
            }
            buckets[index] = buckets[index]->next;
        }
        if(buckets[index]->values.first != key)
        {
            num_of_elements++;
            buckets[index]->next = new S(key,name);
        }
        else
        {
            buckets[index]->values.second = name;
        }
        buckets[index] = head;
        return;
    }
    Name& get(Key key)
    {
        size_t index = hash<Key>{}(key);
        index%=bucket_size;
        S<Key,Name>* head = buckets[index];
        S<Key,Name>* curr = buckets[index];
        while(curr->next != nullptr)
        {
            if(curr->values.first == key)
            {
                break;
            }
            curr=curr->next;
        }
        if(curr->values.first != key)
        {
            curr->next = new S(key,0);
            curr=curr->next;
            num_of_elements++;
        }
        return curr->values.second;
    }
    
};

int main()
{
    hash_map<int,int> mp;
    mp.set(5,6);
    mp.set(10,11);
    mp.set(15,16);
    cout<<mp.get(5)<<endl; // >> 5 6
    cout<<mp.get(10)<<endl; // >> 10 11
    cout<<mp.get(15)<<endl; // >> 15 16
    cout<<mp.get(20)<<endl; // >> 20 ?  >> 20 0
    /*
        6
        11
        16
        0
    */
    mp.set(20,21); // >> 20 21
    cout<<mp.get(20)<<endl;
    /*
        21
    */
    mp.set(26,27); // >> 26 27
    cout<<mp.get(5)<<endl;
    cout<<mp.get(10)<<endl;
    cout<<mp.get(15)<<endl;
    cout<<mp.get(20)<<endl;
    cout<<mp.get(26)<<endl;
    
    /*                    до фикса бага выводило:
        6                 0
        11                0
        16                0
        21                0
        27                27
    */ 




    return 0;
}

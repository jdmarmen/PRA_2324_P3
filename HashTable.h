#pragma once

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include <list>

template <typename V>
class HashTable : public Dict<V>
{

private:
    int n{};
    int max{};
    std::list<TableEntry<V>> *table;

    int h(std::string key);

public:
    HashTable(int size);
    ~HashTable();
    int capacity();
    template <typename F>
    friend std::ostream &operator<<(std::ostream &out, const HashTable<F> &th);
    V operator[](std::string key);

    void insert(std::string key, V value) override;
    V search(std::string key) override;
    V remove(std::string key) override;
    int entries() override;
};

template <typename V>
int HashTable<V>::h(std::string key){
    int sum=0;
    for(int i=0; i<key.size(); i++){
        char c=key.at(i);
        sum+=int(c);
    }

    return sum%capacity();
}

template <typename V>
void HashTable<V>::insert(std::string key, V value){
    int pos = this->h(key);
    
    for(auto& entry :table[pos]){
        if(entry.key==key){
            throw std::runtime_error("Key already exists");
        }
    }
    table[pos].push_back(TableEntry<V>(key,value));
    n++;
}

template <typename V>
V HashTable<V>::search(std::string key){
    int pos=h(key);
    for(auto& entry:table[pos]){
        if(entry.key==key)
            return entry.value;
    }
    std::runtime_error("Key not found");
    return -1;
}

template<typename V>
V HashTable<V>::remove(std::string key){
    int pos=h(key);
    for(auto& entry:table[pos]){
        if(entry.key==key)
            table[pos].remove(entry);
            return 0;
    }
    std::runtime_error("Key not found");
    return -1;
}

template<typename V>
int HashTable<V>::entries(){
    return n;
}

template <typename V>
HashTable<V>::HashTable(int size) : max(size)
{
    table = new std::list<TableEntry<V>>[max];
}

template <typename V>
HashTable<V>::~HashTable()
{
    delete[] table;
}

template <typename V>
int HashTable<V>::capacity()
{
    return max;
}

template <typename V>
V HashTable<V>::operator[](std::string key){
    return search(key); //Already triggers the exception if the key is not found in search()
}

template <typename F>
std::ostream &operator<<(std::ostream &out, const HashTable<F> &th)
{
    for (int i = 0; i < th.max; i++)
    {
        out << "Posicion " << i << ": ";
        for (auto& entry : th.table[i])
        {
            out << entry;
        }
    }
    return out; 
}

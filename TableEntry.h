#pragma once

#include <string>
#include <ostream>

template <typename V>
class TableEntry{

    public:
    std::string key{};
    V value;

    TableEntry(std::string key, V value){

    }

    TableEntry(std::string key){

    }

    TableEntry(){

    }

    friend bool operator == (const TableEntry<V> &te1, const TableEntry<V> &te2){

    }

    friend bool operator != (const TableEntry<V> &te1, const TableEntry<V> &te2){

    }

    friend std::ostream& operator << (std::ostream &out, const TableEntry<V> &te){

    }

    void insert(std::string key, V value) override{

    }

    V search (std::string key) override{

    }

    V remove (std::string key) override{

    }
    
    int entries() override{

    }

};
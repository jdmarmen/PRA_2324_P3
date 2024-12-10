#pragma once

#include <string>
#include <ostream>

template <typename V>
class TableEntry{

    public:
    std::string key{};
    V value{};

    TableEntry(std::string key, V value);

    TableEntry(std::string key);

    TableEntry();

    template <typename F>
    friend bool operator == (const TableEntry<F> &te1, const TableEntry<F> &te2);

    template <typename F>
    friend bool operator != (const TableEntry<F> &te1, const TableEntry<F> &te2);

    template <typename F>
    friend std::ostream& operator << (std::ostream &out, const TableEntry<F> &te);

    template <typename F>
    friend bool operator < (const TableEntry<F> &te1, const TableEntry<F> &te2);

    template <typename F>
    friend bool operator > (const TableEntry<F> &te1, const TableEntry<F> &te2);

};

template <typename V>
TableEntry <V>::TableEntry(std::string key, V value): key(key), value(value){}

template <typename V>
TableEntry <V>::TableEntry(std::string key): key(key){}

template <typename V>
TableEntry <V>::TableEntry():key(""){}

template <typename F>
bool operator == (const TableEntry<F> &te1, const TableEntry<F> &te2){
    if(te1.key==te2.key)
        return true;
    else
        return false;
}

template <typename F>
bool operator != (const TableEntry<F> &te1, const TableEntry<F> &te2){
    if(te1.key!=te2.key)
        return true;
    else
        return false;
}

template <typename F>
std::ostream& operator << (std::ostream &out, const TableEntry<F> &te){
    out<<"Key: "<<te.key<<" || Value: "<<te.value<<std::endl;
    return out;
}

template <typename F>
bool operator < (const TableEntry<F> &te1, const TableEntry<F> &te2){
    return te1.key<te2.key;
}

template <typename F> 
bool operator > (const TableEntry<F> &te1, const TableEntry<F> &te2){
    return te1.key>te2.key;
}
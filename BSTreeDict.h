#pragma once

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        BSTreeDict();
        ~BSTreeDict();
        template <typename F>
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<F> &bs);
        V operator[](std::string key);

        void insert(std::string key, V value)override;
		V search(std::string key)override;
		V remove(std::string key)override;
		int entries()override;

};

template <typename V>
BSTreeDict<V>::BSTreeDict(){
    tree=new BSTree<TableEntry<V>>();
}

template <typename V>
BSTreeDict<V>::~BSTreeDict(){
    delete tree;
}

template <typename F>
std::ostream& operator<<(std::ostream &out, const BSTreeDict<F> &bs){
    out<<*bs.tree<<"\n";
    return out;
}

template <typename V>
V BSTreeDict<V>::operator[](std::string key){
    TableEntry<V> te(key);
    return tree->search(te).value;
}

template <typename V>
void BSTreeDict<V>::insert(std::string key, V value) {
	TableEntry<V> entry(key, value);
	tree->insert(entry);
}

template <typename V>
V BSTreeDict<V>::search(std::string key){
	TableEntry<V> entry(key);
	return tree->search(entry).value;
}

template <typename V>
V BSTreeDict<V>::remove(std::string key){
	TableEntry<V> entry(key);
	V value = tree->search(entry).value;
	tree->remove(entry);
	return value;
}
    
template <typename V>
int BSTreeDict<V>::entries(){
	return this->tree->size();
}


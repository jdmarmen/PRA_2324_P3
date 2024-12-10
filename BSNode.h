#pragma once

#include <ostream>

template <typename T>
class BSNode{

    public:

    T elem;
    BSNode<T>* left{};
    BSNode<T>* right{};

    BSNode(T elem, BSNode<T>* left, BSNode<T>* right);
    template <typename F>
    friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn);

};

template <typename T>
BSNode<T>::BSNode(T elem, BSNode<T>* left, BSNode<T>* right) : elem(elem), left(left), right(right){}

template <typename F>
std::ostream& operator<<(std::ostream &out, const BSNode<F> &bsn){
    out<<bsn.elem<<"\n";
    return out;
}
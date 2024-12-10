#pragma once

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree{
    
    public:

    // creacion y tamaño
    BSTree();
    int size() const;

    // bsuqueda de elementos
    T search(T e) const;
    T operator[] (T e) const;

    // insercion de elementos
    void insert(T e);

    // recorrido e impresion del arbol
    template <typename F>
    friend std::ostream& operator<<(std::ostream &out, const BSTree<F> &bst);

    // eliminacion de elementos
    void remove(T e);

    // destruccion
    ~BSTree();
    
    private:

    int nelem{};
    BSNode<T>* root{};

    // busqueda de elementos
    BSNode<T>* search(BSNode<T>* n, T e) const;
    
    // insercion de elementos
    BSNode<T>* insert(BSNode<T>* n, T e);

    // recorrido e impresion del arbol
    void print_inorder(std::ostream &out,BSNode<T>* n)const;

    // eliminacion de elementos
    BSNode<T>* remove(BSNode<T>* n, T e);
    T max(BSNode<T>* n)const;
    BSNode<T>* remove_max(BSNode<T>* n);

    //destruccion
    void delete_cascade(BSNode<T>* n);
};

template <typename T>
BSTree<T>::BSTree(){}

template <typename T>
int BSTree<T>::size()const{
    return nelem;
}

template <typename T>
T BSTree<T>::search(T e) const{
    return search(root,e)->elem;
}

template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* n, T e) const{
    if(n==nullptr)
        throw std::runtime_error("Element not found");
    else if(n->elem<e)
        return search(n->right,e);
    else if(n->elem>e)
        return search(n->left,e);
    else
        return n;

}

template <typename T>
T BSTree<T>::operator[](T e)const{
    return search(e);
}

template <typename T>
void BSTree<T>::insert(T e){
    root=insert(root,e);
    nelem++;
}

template <typename T>
BSNode<T>* BSTree<T>::insert(BSNode<T>* n, T e){
    if(n==nullptr)
        return new BSNode<T>(e,nullptr,nullptr);
    else if (n->elem==e)
        throw std::runtime_error("Element already exists\n");
    else if(n->elem<e)
        n->right=insert(n->right,e);
    else
        n->left=insert(n->left,e);
    
    return n;
;}

template <typename F>
std::ostream& operator<<(std::ostream &out, const BSTree<F> &bst){
    bst.print_inorder(out,bst.root);
    return out;
}

template <typename T>
void BSTree<T>::print_inorder(std::ostream &out,BSNode<T>* n)const{
    if(n!=nullptr){
        print_inorder(out,n->left);
        out<<n->elem<<"\n";
        print_inorder(out,n->right);
    }
}

template <typename T>
void BSTree<T>::remove(T e){
    remove(root,e);
    nelem--;
}

template <typename T>
BSNode<T>* BSTree<T>::remove(BSNode<T>* n, T e){
    if (n==nullptr)
        throw std::runtime_error("Element not found\n");
    else if(n->elem<e)
        n->right=remove(n->right,e);
    else if(n->elem>e)
        n->left=remove(n->left,e);
    else{
        if(n->left != nullptr && n->right != nullptr){
            n->elem=max(n->left);
            n->left=remove_max(n->left);
        }
        else
            n=(n->left!=nullptr)?n->left:n->right;
    }
    return n;
}

template <typename T>
T BSTree<T>::max(BSNode<T>* n)const{
    if (n==nullptr)
        throw std::runtime_error("Element not found\n");
    else if(n->right!=nullptr)
        return max(n->right);
    else
        return n->elem;
}

template <typename T>
BSNode<T>* BSTree<T>::remove_max(BSNode<T>* n){
    if(n->right==nullptr)
        return n->left;
    else{
        n->right=remove_max(n->right);
        return n;
    }
}

template <typename T>
BSTree<T>::~BSTree(){
    delete_cascade(root);
}

template <typename T>
void BSTree<T>::delete_cascade(BSNode<T>* n){
    if(n!=nullptr){
        delete_cascade(n->left);
        delete_cascade(n->right);
        delete n;
    }
}

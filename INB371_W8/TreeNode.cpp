/*
 * File: UseTree.cpp
 * Exercises the functionality of the Binary Search Tree data structure.
 */

#include <cstddef>
#include <iostream>
#include "TreeNode.h"

using namespace std;

/* Constructor initialises an object of type TreeNode with key and sets left and
   right child pointers to NULL. */
template <typename ElemType>
TreeNode<ElemType>::TreeNode(ElemType key, ValueType val) {
    this->key = key;
    this->lChild = NULL;
    this->rChild = NULL;
}

/* Destructor */
template <typename ElemType>
TreeNode<ElemType>::~TreeNode() {
    // no dynamic objects to delete
}
template <typename ElemType>
/* Accessors to private TreeNode fields */
ElemType TreeNode<ElemType>::GetKey() {
    return key;
}
template <typename ElemType>
TreeNode<ElemType> *TreeNode<ElemType>::GetLChild() {
    return lChild;
}

template <typename ElemType>
TreeNode<ElemType> *TreeNode<ElemType>::GetRChild() {
    return rChild;
}

/* Mutators for attaching new child nodes to an existing node */
//Sets the child of the left node. Inputs pointer to the child in question
template <typename ElemType>
void TreeNode<ElemType>::SetLChild(TreeNode *child) {
    lChild = child;
}

//Sets the child of the right node. Inputs pointer to the child in question
template <typename ElemType>
void TreeNode<ElemType>::SetRChild(TreeNode *child) {
    rChild = child;
}

/* Mutator for key - only used in delete */
template <typename ElemType>
void TreeNode<ElemType>::SetKey(ElemType key) {
    this->key = key;
}

template <typename ElemType>
void TreeNode<ElemType>::SetValue(ValueType val) {

    this->value =  val;

}
template <typename ElemType>
ValueType TreeNode<ElemType>::GetValue() {

    return this->value;

}




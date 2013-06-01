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
TreeNode::TreeNode(KeyType key, ValueType val) {
    this->key = key;
    this->lChild = NULL;
    this->rChild = NULL;
}

/* Destructor */
TreeNode::~TreeNode() {
    // no dynamic objects to delete
}

/* Accessors to private TreeNode fields */
KeyType TreeNode::GetKey() {
    return key;
}

TreeNode* TreeNode::GetLChild() {
    return lChild;
}

TreeNode* TreeNode::GetRChild() {
    return rChild;
}

/* Mutators for attaching new child nodes to an existing node */
void TreeNode::SetLChild(TreeNode *child) {
    lChild = child;
}

void TreeNode::SetRChild(TreeNode *child) {
    rChild = child;
}

/* Mutator for key - only used in delete */
void TreeNode::SetKey(KeyType key) {
    this->key = key;
}

void TreeNode::SetValue(ValueType val){

   this->value =  val;

}
ValueType TreeNode::GetValue(){

   return this->value;

}




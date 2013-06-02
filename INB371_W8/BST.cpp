#include <cstddef>
#include <iomanip>
#include <iostream>
#include "BST.h"

using namespace std;

template <typename TypeName>
BST<TypeName>::BST() {
    tree = NULL;
    size = 0;
}

template <typename TypeName>
BST<TypeName>::~BST() {
    Clear(tree);
}

/* Resturns true if tree is empty, false otherwise */
template <typename TypeName>
bool BST<TypeName>::IsEmpty() {
    return tree == NULL;
}

/* Resturns numnber of nodes in the tree */
template <typename TypeName>
int BST<TypeName>::Size() {
    return size;
}

/* Clears all nodes from the tree */
template <typename TypeName>
void BST<TypeName>::Clear() {
    Clear(tree);
    tree = NULL;
    size = 0;
}

/* Clears all nodes from the tree by recursively walking in post-order
   deleting all dynamically allocated nodes. */
template <typename TypeName>
void BST<TypeName>::Clear(TreeNode<TypeName> *tree) {
    if (tree != NULL) {
        Clear(tree->GetLChild());
        Clear(tree->GetRChild());
        delete tree;
    }
}

/* Search for a key in the tree.  Return true if it exists otherwise return false */
template <typename TypeName>
bool BST<TypeName>::Search(TypeName key) {
    return Search(tree, key);
}

/* Recursive implementation of search function */
template <typename TypeName>
bool BST<TypeName>::Search(TreeNode<TypeName> *tree, TypeName key) {
    if (tree != NULL) {
        if (key == tree->GetKey()) {
            return true;
        } else if (key < tree->GetKey()) {
            return Search(tree->GetLChild(), key);
        } else {
            return Search(tree->GetRChild(), key);
        }
    } else {
        return false;
    }
}

template <typename TypeName>
ValueType BST<TypeName>::GetValue(TypeName key){
    return GetValue(tree, key);
}

template <typename TypeName>
ValueType BST<TypeName>::GetValue(TreeNode<TypeName> *tree, TypeName key) {
    if (tree != NULL) {
        if (key == tree->GetKey()) {
            return tree->GetValue();
        } else if (key < tree->GetKey()) {
            return GetValue(tree->GetLChild(), key);
        } else {
            return GetValue(tree->GetRChild(), key);
        }
    } else {
        return false;
    }
}

/* Insert a key in the tree.  If key already exists, do not insert. */
template <typename TypeName>
void BST<TypeName>::Insert(TypeName key, ValueType val) {
    if (tree == NULL) {
        tree = new TreeNode<TypeName>(key, val);
        size = 1;
    } else {
        Insert(tree, key, val);
    }
}

/* Recursive imeplementation of insert function */
template <typename TypeName>
void BST<TypeName>::Insert(TreeNode<TypeName> *tree, TypeName key, ValueType val) {
    if (key < tree->GetKey()) {
        if (tree->GetLChild() == NULL) {
            tree->SetLChild(new TreeNode<TypeName>(key, val));
            size++;
        } else {
            Insert(tree->GetLChild(), key, val);
        }

        // what happens if explicit check is not made
    } else if (key > tree->GetKey()) {
        if (tree->GetRChild() == NULL) {
            tree->SetRChild(new TreeNode<TypeName>(key, val));
            size++;
        } else {
            Insert(tree->GetRChild(), key, val);
        }
    }
}

/* Delete key in tree if it exists */
template <typename TypeName>
void BST<TypeName>::Delete(TypeName key) {

    // search for item and its parent
    TreeNode<TypeName> *current = tree;
    TreeNode<TypeName> *parent = NULL;
    while (current != NULL && key != current->GetKey()) {
        parent = current;
        if (key < current->GetKey()) {
            current = current->GetLChild();
        } else {
            current = current->GetRChild();
        }
    }

    // check for successful search
    if (current != NULL) {

        // check for case 3:  current has two children
        if (current->GetLChild() != NULL && current->GetRChild() != NULL) {

            // find the right-most node in the left subtree
            if (current->GetLChild()->GetRChild() == NULL) {  // a special case
                TreeNode<TypeName> *temp = current->GetLChild();
                current->SetKey(current->GetLChild()->GetKey());
                current->SetValue(current->GetLChild()->GetValue());
                current->SetLChild(current->GetLChild()->GetLChild());
                delete temp;
                size--;
            } else {
                TreeNode<TypeName> *p = current->GetLChild()->GetRChild();
                TreeNode<TypeName> *pp = current->GetLChild();

                // walk right
                while (p->GetRChild() != NULL) {
                    pp = p;
                    p = p->GetRChild();
                }

                // copy the item at p to current
                TypeName key = p->GetKey();
                current->SetKey(key);
                TreeNode<TypeName> *temp = p->GetLChild();
                pp->SetRChild(temp);
                delete p;
                size--;
            }
        } else {        // cases 1 and 2: item has no child or 1 child
            TreeNode<TypeName> *child;
            if (current->GetLChild() != 0) {
                child = current->GetLChild();
            } else {
                child = current->GetRChild();
            }

            // remove the pointer to the node
            if (current == tree) {
                tree = child;
            } else if (current == parent->GetLChild()) {
                parent->SetLChild(child);
            } else {
                parent->SetRChild(child);
            }
            delete current;
            size--;
        }
    }
}

/* Traverse the tree in key order */
template <typename TypeName>
void BST<TypeName>::InOrderTraversal() {
    InOrderTraversal(tree);
}

/* Recursively traverse the tree in key order */
template <typename TypeName>
void BST<TypeName>::InOrderTraversal(TreeNode<TypeName> *tree) {
    if (tree != NULL) {
        InOrderTraversal(tree->GetLChild());
        cout << tree->GetKey() << " " << setw(3) << tree->GetValue() << endl;
        InOrderTraversal(tree->GetRChild());
    }
}

template <typename TypeName>
void BST<TypeName>::PostOrderTraversal() {
    PostOrderTraversal(tree);
}

template <typename TypeName>
void BST<TypeName>::PostOrderTraversal(TreeNode<TypeName> *tree) {
    if (tree != NULL) {
        PostOrderTraversal(tree->GetLChild());
        PostOrderTraversal(tree->GetRChild());
        cout << tree->GetKey() << " ";
    }
}

template <typename TypeName>
void BST<TypeName>::PreOrderTraversal() {
    PreOrderTraversal(tree);
}

template <typename TypeName>
void BST<TypeName>::PreOrderTraversal(TreeNode<TypeName> *tree) {
    if (tree != NULL) {
        cout << tree->GetKey() << " ";
        PreOrderTraversal(tree->GetLChild());
        PreOrderTraversal(tree->GetRChild());
    }
}

template <typename TypeName>
void BST<TypeName>::Update(TreeNode<TypeName> *tree, TypeName key, ValueType val) {

    if (tree != NULL) {
        if (key == tree->GetKey()) {
            tree->SetValue(val);    //Set the value of the tree node.
        } else if (key < tree->GetKey()) {
            Update(tree->GetLChild(), key, val);
        } else {
            Update(tree->GetRChild(), key, val);
        }
    } else {
        cout << "Update Unsuccessful. Tree is empty" << endl;
    }
}

template <typename TypeName>
void BST<TypeName>::Update(TypeName key, ValueType val) {
    Update(tree, key, val);
}


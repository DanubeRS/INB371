/*
 * File: BST.h
 * Specification for Binary Search Tree.  Can be used as basis for a Set ADT.
 */

#ifndef _bst_h
#define _bst_h

#include "TreeNode.h"

template <typename TypeName>
class BST {

public:
    /* Constructor sets tree tree to NULL*/
    BST();

    /* Destructor deletes all dynamically created TreeNodes */
    ~BST();

    /* Information Functions */
    bool IsEmpty();
    int Size();

    /* Insert key in tree if it does not exist */
    void Insert(TypeName key, ValueType val);

    /* Delete key in tree if it exists */
    void Delete(TypeName key);

    /* Search for a key in the tree.  Return true if it exists otherwise return false */
    bool Search(TypeName key);

    /* Clear the contents of the BST */
    void Clear();

    //Update the contents of a treenode
    void Update(TypeName key, ValueType val);

    // traversals
    void PreOrderTraversal();
    void InOrderTraversal();
    void PostOrderTraversal();

    ValueType GetValue(TypeName key);

private:
    TreeNode<TypeName> *tree;
    int size;
    void Clear(TreeNode<TypeName> *tree);

    /* Inserts the specified key at the appropriate location in the BST rooted at tree. */
    void Insert(TreeNode<TypeName> *tree, TypeName key, ValueType val);


    /* Recursive traversal prototypes */
    void InOrderTraversal(TreeNode<TypeName> *tree);
    void PreOrderTraversal(TreeNode<TypeName> *tree);
    void PostOrderTraversal(TreeNode<TypeName> *tree);

    /* Recursive implementation of search function */
    bool Search(TreeNode<TypeName> *tree, TypeName key);

    void Update(TreeNode<TypeName> *tree, TypeName key, ValueType val);

    ValueType GetValue(TreeNode<TypeName> *tree, TypeName key);
};

#endif //_bst_h

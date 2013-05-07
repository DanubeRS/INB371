/*
 * File: BST.h
 * Specification for Binary Search Tree.  Can be used as basis for a Set ADT.
 */

#ifndef _bst_h
#define _bst_h

#include "TreeNode.h"

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
    void Insert(KeyType key, ValueType val);

    /* Delete key in tree if it exists */
    void Delete(KeyType key, ValueType val);

	/* Search for a key in the tree.  Return true if it exists otherwise return false */
    ValueType Search(KeyType key);

    /* Clear the contents of the BST */
    void Clear();

    // traversals
    void PreOrderTraversal();
    void InOrderTraversal();
    void PostOrderTraversal();

    void Update(KeyType key, ValueType val);

private:
    TreeNode *tree;
	int size;
    void Clear(TreeNode *tree);

    /* Inserts the specified key at the appropriate location in the BST rooted at tree. */
    void Insert(TreeNode *tree, KeyType key, ValueType val);


    /* Recursive traversal prototypes */
    void InOrderTraversal(TreeNode *tree);
    void PreOrderTraversal(TreeNode *tree);
    void PostOrderTraversal(TreeNode *tree);

	/* Recursive implementation of search function */
    ValueType Search(TreeNode *tree, KeyType key);
    void Update(TreeNode *tree, KeyType key, ValueType val);
};

#endif // _bst_h

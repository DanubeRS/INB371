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
    void Insert(ElemType key);

    /* Delete key in tree if it exists */
    void Delete(ElemType key);

	/* Search for a key in the tree.  Return true if it exists otherwise return false */
    bool Search(ElemType key);

    /* Clear the contents of the BST */
    void Clear();

    // traversals
    void PreOrderTraversal();
    void InOrderTraversal();
    void PostOrderTraversal();

private:
    TreeNode *tree;
	int size;
    void Clear(TreeNode *tree);

    /* Inserts the specified key at the appropriate location in the BST rooted at tree. */
    void Insert(TreeNode *tree, ElemType key);


    /* Recursive traversal prototypes */
    void InOrderTraversal(TreeNode *tree);
    void PreOrderTraversal(TreeNode *tree);
    void PostOrderTraversal(TreeNode *tree);

	/* Recursive implementation of search function */
    bool Search(TreeNode *tree, ElemType key);
};

#endif // _bst_h

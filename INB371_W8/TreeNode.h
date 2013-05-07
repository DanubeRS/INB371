/*
 * File: TreeNode.h
 * Specification for TreeNode to be used in a Binary Search Tree
 */

#ifndef _treenode_h
#define _treenode_h

#include <string>

typedef     std::string     KeyType;
typedef     int             ValueType;

class TreeNode
{
private:

    // data
    KeyType key;
    ValueType val;

    // pointers to child nodes
    TreeNode *lChild;
    TreeNode *rChild;

public:
    /*Constructor initialises an object oif type TreeNode with key and sets left and
      right child pointers to NULL. */
    TreeNode(KeyType key, ValueType val);

    /* Destructor */
    ~TreeNode();

    /* Accessors to private TreeNode fields */
    KeyType GetKey();
    TreeNode *GetLChild();
    TreeNode *GetRChild();

    /* Mutators for attaching new child nodes to an existing node */
    void SetLChild(TreeNode *child);
    void SetRChild(TreeNode *child);

    /* Mutator for key - only used in delete */
    void SetKey(KeyType key);

    void SetValue(ValueType val);

    ValueType GetValue();


};

#endif

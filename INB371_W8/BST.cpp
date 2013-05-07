#include <cstddef>
#include <iostream>
#include "BST.h"

using namespace std;


BST::BST() {
    tree = NULL;
	size = 0;
}

BST::~BST() {
    Clear(tree);
}

/* Resturns true if tree is empty, false otherwise */
bool BST::IsEmpty() {
    return tree == NULL;
}

/* Resturns numnber of nodes in the tree */
int BST::Size() {
    return size;
}

/* Clears all nodes from the tree */
void BST::Clear() {
    Clear(tree);
    tree = NULL;
    size = 0;
}

/* Clears all nodes from the tree by recursively walking in post-order
   deleting all dynamically allocated nodes. */
void BST::Clear(TreeNode *tree) {
    if (tree != NULL) {
        Clear(tree->GetLChild());
        Clear(tree->GetRChild());
        delete tree;
    }
}

/* Search for a key in the tree.  Return true if it exists otherwise return false */
bool BST::Search(ElemType key) {
    return Search(tree, key);
}

/* Recursive implementation of search function */
bool BST::Search(TreeNode *tree, ElemType key) {
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

/* Insert a key in the tree.  If key already exists, do not insert. */
void BST::Insert(ElemType key) {
    if (tree == NULL) {
        tree = new TreeNode(key);
		size = 1;
    } else {
        Insert(tree, key);
    }
}

/* Recursive imeplementation of insert function */
void BST::Insert(TreeNode* tree, ElemType key) {
    if (key < tree->GetKey()) {
        if (tree->GetLChild() == NULL) {
            tree->SetLChild(new TreeNode(key));
			size++;
        } else {
            Insert(tree->GetLChild(), key);
        }

    // what happens if explicit check is not made
    } else if (key > tree->GetKey()){
        if (tree->GetRChild() == NULL) {
            tree->SetRChild(new TreeNode(key));
			size++;
        } else {
            Insert(tree->GetRChild(), key);
        }
    }
}

/* Delete key in tree if it exists */
void BST::Delete(ElemType key) {

    // search for item and its parent
    TreeNode *current = tree;
    TreeNode *parent = NULL;
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
                TreeNode *temp = current->GetLChild();
                current->SetKey(current->GetLChild()->GetKey());
                current->SetLChild(current->GetLChild()->GetLChild());
                delete temp;
                size--;
            } else {
                TreeNode *p = current->GetLChild()->GetRChild();
                TreeNode *pp = current->GetLChild();

                // walk right
                while (p->GetRChild() != NULL) {
                    pp = p;
                    p = p->GetRChild();
                }

                // copy the item at p to current
                ElemType key = p->GetKey();
                current->SetKey(key);
                TreeNode *temp = p->GetLChild();
                pp->SetRChild(temp);
                delete p;
                size--;
            }
        } else {        // cases 1 and 2: item has no child or 1 child
            TreeNode *child;
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
void BST::InOrderTraversal() {
    InOrderTraversal(tree);
}

/* Recursively traverse the tree in key order */
void BST::InOrderTraversal(TreeNode *tree) {
    if (tree != NULL) {
        InOrderTraversal(tree->GetLChild());
        cout << tree->GetKey() << " ";
        InOrderTraversal(tree->GetRChild());
    }
}

void BST::PostOrderTraversal() {
    PostOrderTraversal(tree);
}

void BST::PostOrderTraversal(TreeNode *tree) {
    if (tree != NULL) {
        PostOrderTraversal(tree->GetLChild());
        PostOrderTraversal(tree->GetRChild());
        cout << tree->GetKey() << " ";
    }
}

void BST::PreOrderTraversal() {
    PreOrderTraversal(tree);
}

void BST::PreOrderTraversal(TreeNode *tree) {
    if (tree != NULL) {
        cout << tree->GetKey() << " ";
        PreOrderTraversal(tree->GetLChild());
        PreOrderTraversal(tree->GetRChild());
    }
}


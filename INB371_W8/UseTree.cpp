#include <iostream>
#include "BST.h"

using namespace std;

int main() {

    // instantiate a tree
    BST tree;
    cout << "a was " << (tree.Search('a') ? "" : "not ") << "found" << endl;
    cout << "Tree contains " << tree.Size() << " keys" << endl;
    cout << "Tree is " << (tree.IsEmpty() ? "" : "not ") << "empty" << endl;

    // insert some elements
    tree.Insert('g');
    tree.Insert('d');
    tree.Insert('e');
    tree.Insert('a');
    tree.Insert('a');

    // walk the tree in key order
    tree.InOrderTraversal();
    cout << endl;

    // search for some elements that exist and some that don't exist
    cout << "a was " << (tree.Search('a') ? "" : "not ") << "found" << endl;
    cout << "b was " << (tree.Search('b') ? "" : "not ") << "found" << endl;
    cout << "c was " << (tree.Search('c') ? "" : "not ") << "found" << endl;
    cout << "d was " << (tree.Search('d') ? "" : "not ") << "found" << endl;
    cout << "e was " << (tree.Search('e') ? "" : "not ") << "found" << endl;
    cout << "f was " << (tree.Search('f') ? "" : "not ") << "found" << endl;
    cout << "g was " << (tree.Search('g') ? "" : "not ") << "found" << endl;

    cout << "Tree contains " << tree.Size() << " keys" << endl;
    cout << "Tree is " << (tree.IsEmpty() ? "" : "not") << " empty" << endl;

    tree.Clear();
    cout << "a was " << (tree.Search('a') ? "" : "not ") << "found" << endl;
    cout << "Tree contains " << tree.Size() << " keys" << endl;
    cout << "Tree is " << (tree.IsEmpty() ? "" : "not ") << "empty" << endl;

    tree.Insert('E');
    tree.Insert('C');
    tree.Insert('G');
    tree.Insert('A');
    tree.Insert('B');
    tree.Insert('D');
    tree.Insert('F');
    tree.Insert('H');
    tree.InOrderTraversal();
    cout << endl;
    tree.PreOrderTraversal();
    cout << endl;
    tree.PostOrderTraversal();
    cout << endl;

    cout << "Tree contains " << tree.Size() << " keys" << endl;
    tree.Delete('H');
    tree.Delete('A');
    tree.Delete('E');
    tree.Delete('A');

    cout << "A was " << (tree.Search('A') ? "" : "not ") << "found" << endl;
    cout << "Tree contains " << tree.Size() << " keys" << endl;
    cout << "Tree is " << (tree.IsEmpty() ? "" : "not ") << "empty" << endl;
    tree.InOrderTraversal();
    cout << endl;

    tree.Delete('B');
    tree.Delete('C');
    tree.Delete('D');
    tree.Delete('F');
    tree.Delete('G');
    cout << "Tree contains " << tree.Size() << " keys" << endl;
    cout << "Tree is " << (tree.IsEmpty() ? "" : "not ") << "empty" << endl;

    return 0;
}

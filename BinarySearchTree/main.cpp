//
//  main.cpp
//  BinarySearchTree
//
//  Created by wuge on 15/11/8.
//  Copyright (c) 2015年 wuge. All rights reserved.
//

#include <iostream>

#include "bst.h"
using namespace std;

void BSTFind(int data, BST tree) {
    cout << "find " << data << " in tree, is " << tree.exist(data) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int data[10] = {5, 3, 7, 6, 1, 9, 8, 4, 0, 2};
    BST tree(NULL);
    
    for (int i = 0; i < 10; i++) {
//        BSTNode* tn = new BSTNode(data[i]);
        tree.addNode(data[i]);
        cout << "the tree after insert " << data[i] << ":" << endl;
//        tree.showTree();
    }
    
    tree.showTree();
    
    BSTFind(10, tree);
    BSTFind(9, tree);
    
    return 0;
}

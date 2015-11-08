//
//  bst.h
//  BinarySearchTree
//
//  Created by wuge on 15/11/8.
//  Copyright (c) 2015年 wuge. All rights reserved.
//

#ifndef __BinarySearchTree__bst__
#define __BinarySearchTree__bst__

#include <iostream>

#include "error.h"

using namespace std;

struct BSTNode {
    BSTNode* left;
    BSTNode* right;
    int data;
    BSTNode(int data) : data(data), left(NULL), right(NULL) {}
};

class BST {
private:
    BSTNode* root;
    
public:
    BST() : root(NULL) {}
    BST(BSTNode* root) : root(root) {}
    ~BST() {
//        delete root;
//        root = NULL;
    }
    
    void addNode(int data, BSTNode* node) {
        BSTNode* cur = node;
        
        if (data < cur->data) {
            if (NULL == node->left) {
                node->left = new BSTNode(data);
                return ;
            } else {
                addNode(data, node->left);
            }
        } else if (data > cur->data) {
            if (NULL == node->right) {
                node->right = new BSTNode(data);
                return ;
            } else {
                addNode(data, node->right);
            }
        } else {
            error("this node of data %d is already in the tree!\n", data);
        }
    }
    
    void addNode(int data) {
        if (NULL == this->root) {
            this->root = new BSTNode(data);
            return ;
        }
        
        addNode(data, this->root);
    }
    
    bool exist(int data) {
        BSTNode* cur = root;
        
        while (NULL != cur) {
            if (data > cur->data) {
                cur = cur->right;
            } else if (data < cur->data) {
                cur = cur->left;
            } else {
                return true;
            }
        }
        
        return false;
    }
    
    void showTree(BSTNode* node) {
        if (NULL == node) {
            return ;
        }
        
        showTree(node->left);
        cout << node->data << endl;
        showTree(node->right);
    }
    
    void showTree() {
        showTree(this->root);
    }
};

#endif /* defined(__BinarySearchTree__bst__) */

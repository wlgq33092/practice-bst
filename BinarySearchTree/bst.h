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
#include <vector>

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
    vector<BSTNode *> nodes;
    
public:
    BST() : root(NULL) {}
    BST(BSTNode* root) : root(root) {}
    ~BST() {
        cout << "nodes size is " << nodes.size() << endl;
        for (int i = 0; i < nodes.size(); i++) {
            BSTNode* tmp = nodes.back();
            delete tmp;
            nodes.pop_back();
        }
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
    
    void midOrder(BSTNode* node) {
        if (NULL == node) {
            return ;
        }
        
        midOrder(node->left);
        cout << node->data << endl;
        nodes.push_back(node);
        midOrder(node->right);
    }
    
    void preOrder(BSTNode* node) {
        if (NULL == node) {
            return ;
        }
        
        cout << node->data << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
    
    void showTree() {
        cout << "midOrder is:" << endl;
        midOrder(this->root);
        
        cout << "preOrder is:" << endl;
        preOrder(this->root);
    }
};

#endif /* defined(__BinarySearchTree__bst__) */

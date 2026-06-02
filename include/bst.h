// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
class BST {
private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;
        
        Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    void insert(Node*& node, const T& key) {
        if (node == nullptr) {
            node = new Node(key);
        } else if (key < node->key) {
            insert(node->left, key);
        } else if (key > node->key) {
            insert(node->right, key);
        } else {
            node->count++;
        }
    }
    
    int search(Node* node, const T& key) const {
        if (node == nullptr) {
            return 0;
        }
        if (key < node->key) {
            return search(node->left, key);
        } else if (key > node->key) {
            return search(node->right, key);
        } else {
            return node->count;
        }
    }
    
    int depth(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
    
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
    
    void collectNodes(Node* node, Node** nodes, int& index) {
        if (node == nullptr) return;
        collectNodes(node->left, nodes, index);
        nodes[index++] = node;
        collectNodes(node->right, nodes, index);
    }
    
    static bool compareByCount(Node* a, Node* b) {
        return a->count > b->count;
    }
    
public:
    BST() : root(nullptr) {}
    
    ~BST() {
        clear(root);
    }
    
    void insert(const T& key) {
        insert(root, key);
    }
    
    int search(const T& key) const {
        return search(root, key);
    }
    
    int depth() const {
        return depth(root);
    }
    
    void printFreq(std::ostream& out) {
        if (root == nullptr) return;
        
        // Подсчет количества узлов
        int size = 0;
        Node** nodes = new Node*[100000]; // Достаточный размер для всех слов
        collectNodes(root, nodes, size);
        
        // Сортировка по убыванию частоты
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (compareByCount(nodes[j+1], nodes[j])) {
                    Node* temp = nodes[j];
                    nodes[j] = nodes[j+1];
                    nodes[j+1] = temp;
                }
            }
        }
        
        // Вывод результатов
        for (int i = 0; i < size; i++) {
            out << nodes[i]->key << ": " << nodes[i]->count << std::endl;
        }
        
        delete[] nodes;
    }
};

#endif  // INCLUDE_BST_H_

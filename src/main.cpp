// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "bst.h"

// Forward declarations
void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    // Создаем дерево
    BST<std::string> tree;
    
    // Загружаем текст из файла
    const char* filename = "src/war_peace.txt";
    makeTree(tree, filename);
    
    // Выводим информацию о дереве
    std::cout << "Tree depth: " << tree.depth() << std::endl;
    
    // Поиск примеров слов
    std::cout << "Search for 'pierre': " << tree.search("pierre") << " times" << std::endl;
    std::cout << "Search for 'natasha': " << tree.search("natasha") << " times" << std::endl;
    std::cout << "Search for 'andrew': " << tree.search("andrew") << " times" << std::endl;
    
    // Выводим частотный анализ в файл и на экран
    printFreq(tree);
    
    return 0;
}

// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cout << "File error!" << std::endl;
        return;
    }
    
    std::string word;
    char ch;
    
    while (file.get(ch)) {
        // Проверяем, является ли символ латинской буквой
        if (isalpha(ch) && (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')) {
            // Преобразуем в нижний регистр
            word += tolower(ch);
        } else {
            // Если встретили не букву и слово не пустое, добавляем в дерево
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }
    
    // Проверяем, осталось ли слово после окончания файла
    if (!word.empty()) {
        tree.insert(word);
    }
    
    file.close();
}

void printFreq(BST<std::string>& tree) {
    // Создаем файл для вывода
    std::ofstream outFile("result/freq.txt");
    
    if (!outFile) {
        std::cout << "Cannot create output file!" << std::endl;
        return;
    }
    
    // Выводим в файл
    tree.printFreq(outFile);
    
    // Также выводим на экран для проверки
    std::cout << "Frequency analysis completed. Results saved to result/freq.txt" << std::endl;
    
    outFile.close();
}

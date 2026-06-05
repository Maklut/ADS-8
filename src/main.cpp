// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  const char* filename = "src/war_peace.txt";
  BST<std::string> tree;

  std::cout << "Building tree from file: " << filename << std::endl;
  makeTree(tree, filename);

  std::cout << "Tree depth: " << tree.depth() << std::endl;

  std::cout << "\nWord frequencies (sorted by frequency):" << std::endl;
  printFreq(tree);

  return 0;
}

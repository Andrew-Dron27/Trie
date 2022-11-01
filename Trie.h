//Andrew Dron u1027713
//A3 Trie and the Rule-Of-Three
#ifndef Trie_H
#define Trie_H
#include "Node.h"
#include <string>
#include <vector>
//Tree of words
//words are represented as pointers to nodes
//each node contains a fixed array of node pointers
class Trie{
  Node* root;
public:
  //default constructor
  Trie();

  //copy constructor
  Trie(const Trie& other);

  //overloaded = operator
  Trie& operator=(Trie other);

  //adds a lowercase word to the trie
  void addAWord(std::string word);

  //checks if the inputted string is a word on the trie
  bool isAWord(std::string word);

  //returns all possible words starting with a given prefix word
  std::vector<std::string> allWordsStartingWithPrefix(std::string word);

  //returns empty vector set to get tests to compile
  std::vector<std::string> allWordsWithWildCardPrefix(std::string words);

  //destructor
  ~Trie();

};
#endif

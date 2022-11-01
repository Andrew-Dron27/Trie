//Andrew Dron u1027713
//A3 Trie and the Rule-Of-Three
#include "Trie.h"
//default constructor
Trie::Trie(){
  root = new Node();
}

//duplicate constructor
Trie::Trie(const Trie& other){
  //root = other.root;
  if(other.root != nullptr){
    root = new Node(*(other.root));
    //root  = other.root;
  }
  else{
    root = new Node();
  }
}

//overloaded = operator
Trie& Trie::operator=(Trie other){
  std::swap(root, other.root);
  return *this;
}

//destructor
Trie::~Trie(){
  delete root;
}

//adds word to the trie
void Trie::addAWord(std::string word){
  root->AddWord(word, 0);
}

//checks wether the input string is a word on the trie
bool Trie::isAWord(std::string word){
  if(word.compare("") == 0){
    return false;
  }
  return root->IsWord(word,0);
}

//returns a vector containing all possible words starting with word
std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string word){
  std::vector<std::string> strings;
  root->GetAllWords(word, strings);
  return strings;
}

//returns an empty vector of strings
std::vector<std::string> allWordsWithWildCardPrefix(std::string words){
  std::vector<std::string> strings;
  return strings;
}

#include "Node.h"
//default constructor
Node::Node(){
  for(int i = 0; i < 26; i++){
    branches[i] = nullptr;//initalize all branches to nullptr
  }
  isAWord = false;
}

//destructor for node
Node::~Node(){
  for(int i = 0; i < 26; i++){
    if(BranchExists(char(i + 97))){
      delete branches[i];//delete every node in branches
    }
    branches[i] = nullptr;
  }
}

//copy constructor for node
Node::Node(const Node& other){
  for(int i = 0; i < 26; i++){
    branches[i] = nullptr;
    if(other.branches[i] != nullptr){
      branches[i] = new Node(*(other.branches[i]));
    }
  }
  isAWord = other.isAWord;
}

//overloaded = operator for node
Node& Node::operator=(Node other){
  std::swap(branches,other.branches);
  std::swap(isAWord,other.isAWord);
  return *this;
}

//returns true if the Node* at the position of char is not null
bool Node::BranchExists(char c){
  int asciiVal = int(c) - 97;//finds the position of the array according to the ascii value of the char
//  std::cout << asciiVal << '\n';
  if(branches[asciiVal] == nullptr){//this checks if this chacater has a value other than nullptr
    return false;
  }
  return true;
}

//adds a character branch to this Node
void Node::AddBranch(char c){
  int asciiVal = (int(c) - 97);//finds the position of the array according to the ascii value of the char

  if(BranchExists(c)){//if the branch already exists do nothing
    return;
  }
  branches[asciiVal] = new Node();
}

//adds a word to the Node and its branches
//position tracks how many branches the function has recursed into
void Node::AddWord(std::string word, unsigned position){
  char charToPlace = word[position];
  int asciiVal = int(charToPlace) - 97;
   if(asciiVal == -97){
    isAWord = true;
    return;
  }
  AddBranch(charToPlace);

  if(position == word.length()){//checks if we are at the last letter in the word
    isAWord = true;
    return;
  }
  branches[asciiVal]->AddWord(word,position+1);
}

//Checks if the word exits in the nodes
//returns false if any of the branches do not exist
bool Node::IsWord(std::string word, unsigned position){
  char charToPlace = word[position];
  int asciiVal = int(charToPlace) - 97;
  if(asciiVal == -97){
    return isAWord;
  }
  if(branches[asciiVal] == nullptr){//checks if the branch does not exist
    return false;
  }
  if(position == word.length()){//if we are at the last letter of the word
    return isAWord;
  }

  return branches[asciiVal]->IsWord(word, position+1);
}

void Node::GetAllWords(std::string prefix, std::vector<std::string>& strings){
  //get the pointer of the node at the end of prefix
  Node* node = GetNodePointer(prefix,0);

  if(node == nullptr){//if word did not exist end function
    return;
  }
  node->GetAllWordsHelper(strings,prefix);
}

//returns a pointer to the node at the end of currPrefix
//if at any time the next letter in prefix does not exist return nullptr
Node* Node::GetNodePointer(std::string prefix, unsigned position){
  if(position == prefix.length()){
    return this;
  }

  char c = prefix[position];
  int val = int(c) - 97;
  if(!BranchExists(c)){
    return nullptr;
  }

  return branches[val]->GetNodePointer(prefix, position+1);
}

//recursive helper method for the get all words function
//adds all possible words to strings given curprefix
void Node::GetAllWordsHelper(std::vector<std::string>& strings,std::string currPrefix){
  if(isAWord){
    strings.push_back(currPrefix);
    strings.push_back("\n");
  }
  //check if this is a leaf with no branches
  if(IsLastWord()){
    return;
  }
  for(int i = 0; i <26; i++){
    if(!(branches[i] == nullptr)){
      char c = char(i + 97);
      branches[i]->GetAllWordsHelper(strings,currPrefix + c);
    }
  }
}

//returns true if no other branches exist on this trie
bool Node::IsLastWord(){
  for(int i = 0; i < 26; i++){
    if(!(branches[i] == nullptr)){
      return false;
    }
  }
  return true;
}

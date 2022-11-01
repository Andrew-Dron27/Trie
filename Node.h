//Andrew Dron u1027713
//A3 Trie and the Rule-Of-Three
#ifndef Node_H
#define Node_H
#include <vector>
#include<string>
#include<iostream>
#include<cstring>
//Node class used for a Trie data structure
//Node contains a fixed array of Node pointers indicated the potential branches of this Node
//Each branch of the node cooresponds to a lowercase letter
//contains a flag that indicates if this Node is the end of a word
class Node{
  Node* branches[26];//potentail branches for this node
  bool isAWord;//flag for if this node is the end of a word
public:
  //constructor
  Node();

  //copy constructor
  Node(const Node& other);

  //overloaded '=' operator
  Node& operator=(Node other);

  //destructor
  ~Node();

  //returns true if branch exists on current node
  bool BranchExists(char c);

  //adds a branch to the branches on this node
  void AddBranch(char c);

  //adds a word to this node
  void AddWord(std::string word, unsigned position);

  //method that checks if the word is made by the Node connections
  bool IsWord(std::string word, unsigned position);

  //returns all possible strings from the nodes given word
  void GetAllWords(std::string prefix,std::vector<std::string>& strings);

private:
  //recursive helper function or getAllWords
  void GetAllWordsHelper(std::vector<std::string>& strings,std::string currPrefix);

  //checks if current node has no existing branches
  bool IsLastWord();

  //returns pointer to node at the end of prefix
  Node* GetNodePointer(std::string prefix, unsigned position);
};
#endif

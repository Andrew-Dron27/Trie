//Andrew Dron u1027713
//A3 Trie and the Rule-Of-Three
#include "Trie.h"
#include "Node.h"
#include <iostream>
#include<vector>
#include<fstream>
#include<iomanip>

int main(int argc, char **argv){
  //if # of command line arguments is incorrect
  if(argc != 3){
    std::cout << "incorrect number of command line paramters please try again" << '\n';
    exit(1);
  }

  //get command line arguments
  std::string dictionary = argv[1];
  std::string queries = argv[2];

  std::ifstream inFileDict;//file for the dictionary
  std::ifstream inFileQue;//file for the quereies
  inFileDict.open(dictionary);
  inFileQue.open(queries);

  //if either file failed to open exit program
  if(!inFileDict || !inFileQue){
    std::cout << "Unable to open file" << '\n';
    exit(1);
  }

  Trie* trie = new Trie();

  std::string x;//holder for the files input
  while(inFileDict >> x){
    trie->addAWord(x);//add every word from the ditionary to the trie
  }

  while(inFileQue >> x){
    if(trie->isAWord(x)){
      std::cout << x << " is found"<<'\n';
    }
    else{
      std::cout << x <<" is not found, did you mean" <<'\n';
      std::vector<std::string> alts = trie->allWordsStartingWithPrefix(x);

      if(alts.size() != 0){
        //if alts is not empty create an iterator and print out all alts
        std::vector<std::string>::iterator it;
        for(it = alts.begin(); it != alts.end();it++){
          std::cout << "   " << *it;
        }
      }
      else{
        std::cout << "   no alternatives found" << '\n';
      }
    }
  }
  inFileQue.close();
  inFileDict.close();

  Trie trietest = Trie();

  Trie trietest2 = Trie();
  trietest.addAWord("hello");
  std::cout << trietest.isAWord("hello") << '\n';
  trietest2 = trietest;
  std::cout << trietest2.isAWord("hello") << '\n';
  Trie trietest3 = trietest;
  bool b = trietest3.isAWord("hello");
  std::cout << b << '\n';
  delete trie;
  return 0;
}

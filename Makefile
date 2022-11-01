CC = g++
GG = -g
Cflags = -Wall
MFlags = -fsanitize=address,undefined

TrieTest: TrieTest.o Trie.o Node.o
	$(CC) -o TrieTest TrieTest.o Trie.o Node.o $(Cflags) $(MFlags) $(GG)

TrieTest.o: TrieTest.cpp Node.h Trie.h
	$(CC) -c TrieTest.cpp $(Cflags) $(MFlags) $(GG)

Trie.o: Trie.h Node.h Trie.cpp Node.cpp
	$(CC) -c Trie.cpp Node.cpp $(Cflags) $(MFlags) $(GG)

Node.o: Node.h Node.cpp
	$(CC)-c Node.cpp $(cflags) $(MFlags) $(GG)

clean:
	$(RM) count *.o *TrieTest

test: TrieTest
	./TrieTest dictionary.txt querieTest.txt

#ifndef TRIE_H
#define TRIE_H

#include <bits/stdc++.h>
#include <string>
#include "node.h"
using namespace std ;

class Trie
{
	friend class Node;
private:
	bool space; //true - if user enters string with spaces
	string no_prefix; 
	Node* root;
public:
	Trie() {root = new Node(); this->space = false;}
	~Trie() {}
	void is_space(string data); //searches user's query string for space and sets bool space appropriately
	bool getSpace() {return space;}
	void insert(string data); //builds trie tree struction
	void search(string data); //wrapper for main auto-completion method; advances to last char in user's prefix
	void print_tree(Node* root, string data, string str); //prints suggested queries
	void print_tree(Node* root, string str); //overloaded print_tree method used for recursion
	void remove_prefix(string data); //removes the prefix (if space in string)
	string getNo_prefix() {return no_prefix;}
	string break_string(string); //returns only prefix (if space in string) used in search and print_tree methods
};

#endif

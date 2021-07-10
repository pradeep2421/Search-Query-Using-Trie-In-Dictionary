#include <bits/stdc++.h>
#include <string>
#include "trie.h"
#include "node.h"
using namespace std ;
void Trie::insert(string data) //insert word
{
	Node* cur = root ;
	for (int i = 0; i < data.length(); i++)
	{
		int current_char = (int)data[i] ;
		if (cur->child[current_char] != NULL) //if there is already a node then no need to make a new node
			cur = cur->child[current_char];
		else
		{
			cur->child[current_char] = new Node(); //if there is no node then make a new node
			cur = cur->child[current_char];
			cur->setChar(data[i]); //insert char in new node
		}
	}
	cur->setWord(true); //word ends ,word =true 
}

void Trie::print_tree(Node* root, string data, string str) //print all the results of the query
{
	for (int i = 0; i < 128; i++) //loop through all the childrens
	{
		Node* adv = root;
		if (adv->child[i] != NULL) //child exists
		{
			adv = adv->child[i]; //advance pointer
			str += adv->getChar(); //append char to end of prefix
			if (adv->isWord()) //if it is a word print it!
			{
				if (this->getSpace() == true) //if query string contained a space 
					cout << this->getNo_prefix();
				  cout << str << endl;
			}
			print_tree(adv, str); //recursive call to keep moving down tree
		}
		str = data; // reset to data
	}
}

void Trie::print_tree(Node* root, string str) //overloaded function for recursive calls
{
	string str_cur = str;

	for (int i = 0; i < 128; i++)
	{
		Node* adv = root;
		if (adv->child[i] != NULL)
		{
			adv = adv->child[i];
			str += adv->getChar();
			if (adv->isWord())
			{
				if (this->getSpace() == true)
					cout << this->no_prefix;
				cout << str << endl;
			}
			print_tree(adv, str);
		}
		str = str_cur;
	}
}

void Trie::search(string data) //search the query string 
{
	Node* cur = root;
	for (int i = 0; i < data.length(); i++) 
	{
		char current_char = (int)data[i] ;
		if (cur->child[current_char] == NULL) //no next child exist
		{
			cout << "error:  string not found" << endl;
			return;
		}
		else {
		cur = cur->child[current_char];
		}
		if (cur->getChar() != data[i]) //current node character doesn't matches with the current index charcter
		{
			cout << "error:  string not found" << endl;
			return;
		}
	}
	if(cur->isWord()){
			if (this->getSpace() == true)
					cout << this->no_prefix;
				cout << data << endl;
	}
	string str = data; 
	print_tree(cur, data, str);	
}

void Trie::is_space(string data) //checks user query string for space char and sets bool space appropriately
{
	for (int i = 0; i < data.length(); i++)
	{
	  if(data[i] == ' '){
		  space = true ;
		  break ;
	  }
	}
}	

string Trie::break_string(string data) //isolates and returns prefix only, if query string contains a space
{
	string current = "" ;

	for (int i = data.length(); i-- > 0;) //reverse loop
	{
		if (data[i] == ' ') //if space, stop and return generic string
			 break;
		else current += data[i] ;//copies chars in generic string begining at the last character until loop encounters a space
	}
	reverse(current.begin() ,current.end()) ;
	return current; //returns the prefix only
}

void Trie::remove_prefix(string data) //method removes the user's query prefix and copies to no_prefix attribute; print to screen along with
												//completed words to offer user search options
{
	for (int i = data.length(); i-- > 0;) //reverse loop
	{
		if (data[i] == ' ') //break loop when space encountered
			break;
		else data.pop_back() ; //each full iteration, last char changed to null char
	}
	no_prefix = data; //copies chars up to first null char into no_prefix string
}
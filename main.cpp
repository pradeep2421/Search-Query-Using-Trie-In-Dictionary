 #include <bits/stdc++.h>
#include <string>
#include <fstream>
#include "trie.h"
#include "node.h"
using namespace std ;
int main(int argc, char const *argv[])
{
	string data ;
	fstream dictionary;
	Trie complete_query;
    int cnt =0 ;
	dictionary.open("dictionary.txt", fstream::in); //read dictionary file into trie tree structure
	if (dictionary.is_open())
	{	
		while (dictionary)
		{

			dictionary >> data;
			complete_query.insert(data);

		}
	}	
	else
	{
		cout << "error:  file not open." << endl;
		return -1;
	}
	dictionary.close();
	data.clear(); //clear string variable used for file input; string variable will read in user input

	bool flag =0 ,endloop = 0 ;

	while(!endloop){
	 
	  cout << "enter word for search" << endl;

	getline(cin, data); //getline used over cin to catch spaces
	complete_query.is_space(data); //checks whether there's a space in user query
	cout << "search results:  " << endl;
	if (complete_query.getSpace() == true) //if a space exists, remove prefix and pass prefix only to search method
	{
		complete_query.remove_prefix(data);
		complete_query.search(complete_query.break_string(data));
	}
	else //if no method exists, pass user's query to search method to auto-complete the query
		complete_query.search(data);

     cout<<"To search another word Enter 1 or Enter 0 to exit"<<endl ;
	 string cur ;
	 
	  cin>>cur ;
	 
	 if(cur == "1") endloop = 0 ;
	 else endloop = 1 ;

      cin.ignore() ;
	}
	
	return 0;
} 	

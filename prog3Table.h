//Viktoriya Petrova
//CS 163
//Program 3
//November 2, 2020
//
//This code contains the constant variables associated with the hash table data structure, and a table of type class.
//The data structure created with this code is a hash table with chaining as the collision resolution. This means
//that a dynamically allocated array of head pointers is created and each item entered is assigned an index number by
//the hash funciton. Each index has a head pointer to linear linked list which contains all items assigned. The function
//prototypes in this code all deal with building and manioulating the hash table structure. Most importantly it serves
//as a search tool to find an item of interest. 

//Pre-processor statement
#include "prog3Queue.h"

//Constant variables
const int SIZE = 37;
const int efItems = 75;

//This class contains the funciton prototypes of the hash table structure and the pointer to the array
//of head pointers. 
class table
{
	public:
		table();                                     //Constructor
		~table();                                    //Destructor
		int hashFunction(char *key);                 //Converts a key into an index number
                int readInFile(item &toAdd);                 //Loads in all info stored in the External File
		int insert(char *keyValue, item &toAdd);     //Adds an item to table
		int remove(char *remName);                   //Removes an item by name
		int retrieve(char *findName, item  &anItem); //Retrieve an item by name. DOES NOT DISPLAY
		int displayByKey(char *keyValue);            //Display all items for matching key
		int displayInv();                            //Displays all saved items in the hash table
	private:
		node **hashTable;                           //dynamically allocated array of head ptrs
};

//Viktoriya Petrova
//CS 163
//Program 3
//November 2, 2020
//
//This section of the code implements all funcitons associated with the Hash Table data structure. The data structure consists of
//a dynamically allocated array of head pointer. The head pointers point to a LLL of items stored under the same index number. The
//structure converts the name of an object into an index number by using a hash function. All data in the hash funciton comes
//from an external file named 'availableItems.txt'. 

//Pre-processor statements
#include "prog3Table.h"
using namespace std;

//Constructor. Initiallizes all private data member to 0 or their 0 equivallent value. A loop is used to initiallize every 
//single index of the dynamic array to NULL. 
table::table()
{
   hashTable = new node* [SIZE];
   for(int i = 0; i < SIZE; ++i)
       hashTable[i] = NULL;
}

//Destructor. Deallocated all dynamic memory and re-sets all private data members to 0 or their 0 equivallent value. 
table::~table()
{
    node *head = NULL;
    node *temp = NULL;

    for(int i = 0; i < SIZE; ++i)
    {
	 head = hashTable[i];
	 while(head)
	 {
	      temp = head -> next;
	      delete head;
	      head = temp;
	 }
    }
    delete [] hashTable;
}
	     

//The purpose of this function is to take in an item name and convert it into an index number using a mathematical formula. 
//It returns the index number generated. 
int table::hashFunction(char *key)
{
     int len = strlen(key);
     int result = 0;

     for(int i = 0; i < len; ++i)
	result += key[i] + i;

     return result % SIZE;
}

//The purpose of this function is to load the information stored in the external file into the hash table. The name of the file
//is 'availableItems.txt'. This funciton calls on the insert function in order to add each item to the hash table as it is being 
//read in.  
int table::readInFile(item &toAdd)
{
    char name[100];
    char location[100];
    char hint[100];
    int i = 0;
    ifstream fileIn;

    fileIn.open("availableItems.txt");
    if(fileIn)
    {
	  fileIn.get(name, 100, '|'); fileIn.ignore(100, '|');
	  while(!fileIn.eof() && i < efItems)
	  {
	       fileIn.get(location, 100, '|'); fileIn.ignore(100, '|');
	       fileIn.get(hint, 100, '\n'); fileIn.ignore(100, '\n');
               toAdd.copyAll(name, location, hint);
	       insert(name, toAdd);
	       ++i;
	       fileIn.get(name, 100, '|'); fileIn.ignore(100, '|');
	  }
	  fileIn.close();
     }

     return 1;
}

//The purpose of this function is to add an item to the hash table. It calls on the hashFunction function in order to convert the
//name that is being passed in into an interger index number. Once it recieves that index number it appends at the head node of that
//respective index. If adds succesfully it will return 1. Otherwise it will return 0.  
int table::insert(char *keyValue, item &toAdd)
{
     int index = hashFunction(keyValue);

     node *temp = new node;
     if(!temp -> entry.addAll(toAdd))
     {
	  delete temp;
	  return 0;
     }

     temp -> next = hashTable[index];
     hashTable[index] = temp;


     return 1;
}

//This function removes a single item from the hash table. It takes in the name of the item that needs to be removed and it 
//calls upon the hashFunction function in order to get the index location of that item. It calls a compare function to look
//for a match at that index. If a match is found the function will delete the matching item and return 1. If no match is found it
//will not do anything and return a 0. 
int table::remove(char *remName)
{
     int index = hashFunction(remName);
     node *head = hashTable[index];
	
     if(!head) return 0;
     if(!head -> next && head -> entry.compare(remName))
     {
	  delete head;
	  head = NULL;
	  hashTable[index] = NULL;
	  return 1;
     }

     if(head -> entry.compare(remName))
     {
	  hashTable[index] = head -> next;
	  delete head;
	  return 1;
     }

     node *current = head;
     node *previous = NULL;
     while(current && !current -> entry.compare(remName))
     {
          previous = current;
          current = current -> next;
     }

     if(current)
     {
          previous -> next = current -> next;
      	  delete current;
	  return 1;
     }

     return 0;
}

//The purpose of this function is to provide the information of a single item with a matching name. If the name being passed in 
//is empty the function will return 0. Otherwise it calls upon the hashFunction function in order to find the correct index
//location of the item. After that it calls the compare function to look for a match. If a match is found it will save the
//information of the requested item and return a 1. If no mathc is found it will not do anything and return a 0. 
int table::retrieve(char *findName, item &anItem)
{
     if(!findName) return 0;
     int index = hashFunction(findName);
     node *head = hashTable[index];

     if(!head) return 0;
     while(head && !head -> entry.compare(findName))
	  head = head -> next;
 
     if(head && anItem.addAll(head -> entry))
	  return 1;
	    

     return 0;
}

//The purpose of this function is to display all information for a particular matching key. It gets passed in a name of an item
//which is converted into an index number by the hashFunction function. If the head pointer at that index locaton is NULL the 
//function will return a 0. If that index contains one or more items it will display the full content of the LLL at that index 
//location and return a 1. 
int table::displayByKey(char *keyValue)
{
     if(!keyValue) return 0;
     int index = hashFunction(keyValue);
     node *current = hashTable[index];

     if(!current) return 0;
     while(current)
     {
	  if(!current -> entry.displayFull())
	       return 0;
	  current = current -> next;
     }

     return 1;
}

//The purpose of this function is to display the full content of the hash table including the index number for each item stored. 
//This function is mainly used to check if all other function had the desired outcome. If the head pointer at an index is NULL
//the function will display a message saying index is empty. If the index has one or more item it will display all items saved. 
//If the function is unable to display for any reason it will return 0. Otherwise it will return 1. 
int table::displayInv()
{
     node *current = NULL;
     for(int i = 0; i < SIZE; ++i)
     {
	 current = hashTable[i];
	 if(!current)
            cout <<endl <<"The content of Index " << i <<" is empty" <<endl <<endl;
	 while(current)
	 { 
	    cout <<endl <<"The content of Index " << i <<":" <<endl <<endl;
	    if(!current -> entry.displayFull())
		 return 0;
	    current = current -> next;
	 }
     }

     return 1;
}

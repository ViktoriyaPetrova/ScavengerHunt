//Viktoriya Petrova
//CS 163
//Program 3
//November 2, 2020
//
//This code contains all function implementations for a single item. It contains multiple copy functions and multiple
//display finctions becuase different parts of the program require specific information about the item to be either
//copied or displayed. 

//Pre-processor statements
#include "prog3Item.h"
using namespace std;

//Constructor. All data members are initialized to 0 or their zero equivallent value. 
item::item()
{
   name = NULL;
   location = NULL;
   hint = NULL;
}

//Destructor. ALl dynamic memory is deallocated and all data members are initiallized to 0 
//or their zero equivallent value. 
item::~item()
{
   if(name) delete [] name;
   if(location) delete [] location;
   if(hint) delete [] hint;
   name = location = hint = NULL;
}


//Copies only the name. Used for the Queue structure. Creates a deep copy of an item's name and stores it in
//a dynamically allocated array of characters. If the name passed in is empty it will return 0 for failure. 
int item::copy(char *nameToAdd)
{
   if(!nameToAdd) return 0; 

   name = new char[strlen(nameToAdd) + 1 ];
   strcpy(name, nameToAdd);

   return 1;
}

//Copies the name, location, and hint. Used for Hash Table structure. Creates a deep copy of an item's name,
//location, and hint and stores it into dynamically allocated arrays of characters. If the name, locatiom, or
//hint array is empty it will return 0 for failure.
int item::copyAll(char *nameToAdd, char *locationToAdd, char *hintToAdd)
{
   if(!nameToAdd || !locationToAdd || !hintToAdd) return 0;

   name = new char[strlen(nameToAdd) + 1];
   strcpy(name, nameToAdd);

   location = new char[strlen(locationToAdd) + 1];
   strcpy(location, locationToAdd);

   hint = new char[strlen(hintToAdd) + 1];
   strcpy(hint, hintToAdd);

   return 1;
}


//Packages the name of an item data member into a class variable. Used throughout the program when working
//with only the name of an item. It returns the value received from the copy function. 
int item::add(item &anItem)
{
    return copy(anItem.name);
}

//Package all information about an item into a class variable. Used throughout the program when working
//with the full item. It returns the falue received from the copyALL function. 
int item::addAll(item &anItem)
{
    return copyAll(anItem.name, anItem.location, anItem.hint);
}

//Has the ability to display the name and location of an item. Used primarily in the queue data structure. If the name
//passed in is empty it will return 0 for failure. If the name is not empty but the location is empty it will display
//only the name and return 1. If both the name and location are not empty it will display both and return 1. 
int item::display()
{
    if(!name) return 0;

    if(name) cout <<"Item: " <<name <<endl;

    if(location) cout <<"Location: " <<location <<endl;

    return 1;
}

//This function has the ability to display only the hint. It is only used when playing the game. It lets the user
//see the hint for a single item. If the item hint is invalid it will return 0 for failure. 
int item::displayHint()
{
    if(!hint) return 0;
    cout <<"Hint: " <<hint <<endl;

    return 1;
}

//This function displays the name, location, and hint of an item. It is used for the hash table display functions. 
//If the name, location, or hint requested are empty it will return 0 for failure. 
int item::displayFull()
{
    if(!name || !location || !hint)  return 0;

    cout <<"Name: " <<name << '\n' <<"Location: " <<location << '\n' <<"Hint: " <<hint <<endl;

    return 1;
}

//This function looks for a match between two item names. It is used by the hash function data structure. If the name
//passed in is empty or if there was no match it will return 0 for failure. If a match is found it will return 1. 
int item::compare(char remName[])
{
    if(!remName) return 0;

    if(strcmp(remName, name) == 0)
	 return 1;
    else
         return 0;
}

//This funciton connects the two data structures together and acts like the glue when testing the game play. It 
//takes the name of an item contained in a class and copies it into an array of characters that can then be used
//as an argument in a function. If the name passed in is empty it will return a 0 for failure. 
int item::transferName(item &anItem, char *name)
{
    if(!anItem.name) return 0; 

    strcpy(name, anItem.name);

    return 1;
}

//This is a utility function that lets the user decide if they would like to repeat a task. If the user responds 
//with a yes it will return a 1. Otherwise the funciton will return a 0. 
int again()
{

    char response; 

    cout <<"Again?(Y/N) " ;
    cin >> response; cin.ignore(20, '\n');
    cout <<endl;

    if(toupper(response) == 'Y')
	  return 1;
    else
	  return 0;
}

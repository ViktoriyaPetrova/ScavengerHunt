//Viktoriya Petrova
//CS 163
//Program 3
// November 2, 2020
//
// This section of the code contains the data members and function prototypes for a single item. All functions
// are designed to work with and manipulate a single item's information. All data members are private and 
// allocated dynamically. This code also contains one utility function that asks the user if they would like
// to repeat a task. 



//Pre-processor statements
#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>

//This class contains the data members and funciton prototypes for a single item. 
class item
{
	public:
		item();                        //Constructor
		~item();                       //Destructor
		int copy(char *nameToAdd);     //Deep copies just the name of an item
		int copyAll(char *nameToAdd, char *locationToAdd, char *hintToAdd); //Dee[ copies all info about an item
		int add(item &anItem);         //Adds only the name into the ADT's dynamic memory
		int addAll(item &anItem);      //Adds all item info into the ADT's dynamic memory
		int display();                 //Displays only the name of an item
		int displayFull();             //Displays the full info of an item
		int displayHint();             //Displays only the hint of an item
		int compare(char remName[]);   //Looks for match
		int transferName(item &anItem, char *name);   //Copies an item name from a class data member to a char array
	private:
		char *name;                    //Name of an item
		char *location;                //Location of the item
		char *hint;                    //A hint for the item
};

//Utility function
int again();                 //Asks the user if they would like to repeat a task






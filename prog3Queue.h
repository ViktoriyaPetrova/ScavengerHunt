//Viktoriya Petrova
//CS 163
//Program 3
//November 2, 2020
//
//
//This code contains the Queue data structure. It consists of a node of type struct and a queue of type class. The node
//is used to create a CLL which contains the name of a single item in each node and a pointer to the next node. The queue
//contains all function prototyes used to manipulate the CLL as well as a pointer to the rear of the list. 
//
//Pre-processor statements
#include "prog3Item.h"

//This struct contains the node information for both the CLL and the hash table collision resolution LLL. 
struct node
{
	item entry;                //Holds the name of a single item
	node *next;               //Pointer to the next node
};

//This class contains all function prototypes needed ot manipulate the CLL.
class queue
{
	public:
		queue();                        //Constructor
		~queue();                       //Destructor
		int enqueue(item &toAdd);       //Add an item to the list
		int dequeue();                  //Remove an item from the list
		int peek(item &anItem);         //View the first item in the list
		int isEmpty();                  //Check if the list is empty
		int displayAll();               //Wrapper function used to display the full list
	private:
		node *rear;                     //A pointer to the rear of the list
		int displayAll(node *rear);     //Recursive function to display the full list
};



//Viktoriya Petrova
//CS 163
//Program 3
//November 2, 2020
//
//This section of the code implements the queue functions. It uses a node struct to build a CLL. All new data is added at the
//rear and all data is removed from the begining of the list. The rear's next pointer points to the first node in the list
//making it a circle. The requiremnt for 'implement one funciton recursively' is met here with the displayALl function. 

//Pre-porcessor statements
#include "prog3Queue.h"
using namespace std;

//Constructor. All private data members are initiallized to 0 or their 0 equivallent values. 
queue::queue()
{
	rear = NULL;
}

//Destructor. All dynamic memory is deallocated and all private data members are set to 0 or their 
//zero equivallent value. 
queue::~queue()
{
	if(!rear) return;
        node *head = rear -> next;
	node *temp = NULL;
	rear -> next = NULL;
	while(head)
	{
	  temp = head -> next;
	  delete head;
	  head = temp;
	}

	rear = NULL;
}
	   

//Adds an item to the end of the list. All items are added at the rear by using the rear pointer. If the list is empty the
//function will create a new node and add the information. If the information being passed in is empty it will return 0. If
//the list has at least one item the funciton will add the new item at the end and update the rear pointer. If its succesfully
//adds the new item it will return a 1. 
int queue::enqueue(item &toAdd)
{
   if(!rear)
   {
	  rear = new node;
	  if(!rear -> entry.add(toAdd))
	  {
	       delete rear;
	       rear = NULL;
	       return 0;
	  }

	  rear -> next = rear;
	  return 1;
    }

    node *temp = rear -> next;
    rear -> next = new node;
    if(!rear -> next -> entry.add(toAdd))
    {
	 delete rear -> next;
	 rear -> next = temp;
	 return 0;
    }

    rear = rear -> next;
    rear -> next = temp;

    return 1;
}

//The purpose of this function is to delete an item from the beginning of the list. If the list is empty the function
//will not delete anything and will return a 0 for failure. If the list has only one node it will delete that node and
//update the rear pointer to NULL. If there is more than one node it will delete the first node in the list and update
//the rear-> next pointer. If it succesfully removes a node it will return a 1 for success. 
int queue::dequeue()
{
   if(!rear) return 0;

   if(rear == rear -> next)
   {
	   delete rear;
	   rear = NULL;
	   return 1;
   }

   node *temp = rear -> next -> next;
   delete rear -> next;
   rear -> next = temp;

   return 1;
}

//The purpose of this function is to provide the information of the item that is located at the beginning of the list.
//If the list is empty the function will return a 0 for failure. If the list contains one or more items it will save the information
//of the correct item and return 1 for success. 
int queue::peek(item &anItem)
{
	if(!rear) return 0;

	if(rear == rear -> next)
	{
		if(anItem.add(rear -> entry))
			return 1;
		else
			return 0;
	}

	if(anItem.add(rear -> next -> entry)) return 1;

    return 0;
}

//The purpose of this function is to check if the list is empty. If it is empty it will return a 0. If there is one or more
//items it will return a 1. 
int queue::isEmpty()
{
    if(!rear) return 0;

    return 1;
}

//The purpose of this function is to display the full content of the list. This portion is the wrapper function which checks
//if the list is empty or if the list contains only one node. If the list is empty the function will return a 0. If it only
//has one node it will display the contents of that node and return 1. If the list contains more than one node the function
//will call on the recursive portion. This function does not have any arguments in order to shield the client program from 
//having to know that a node is being used. 
int queue::displayAll()
{
    if(!rear) return 0;
    if(rear == rear -> next)
    {
	   rear -> entry.display();
	   return 1;
    } 

    return displayAll(rear -> next);
}

//This is the recursive portion of the display all function. The purpose is to display the content of every single node
//in the CLL. The base case is when rear is NULL or when there is only one node. This funciton will recurively call on itself 
//in order to display all items one by one. When it is finished it will return 1 for success. 
int queue::displayAll(node *rear)
{
    if(!rear) return 0;
    if(this -> rear == rear)
    {
	 rear -> entry.display();
	 return 1;
    }

    rear -> entry.display();
    displayAll(rear -> next);

    return 1;
}

//Viktoriya Petrova
//CS 163
//Program 3
//November 2, 2020
//
//This code contains the 'Main' portion of the program. This is where all function calls are made and where the client program
//is simulated so that the data structures can be tested. There is a  main menu which lets the tester chose from 3 different options: 
//testing the game, testing the queue data structure, and testing the hash table data structure. When testing the game, different
//parts of the hash table data structure and the queue data structure are called upon based on what is needed at that moment. When 
//testing the queue the tester is given a menu of options to chose from so that different aspects of the queue can be fully tested. 
//The same goes for the hash table option. A menu of choices is provided so that all aspects can be fully tested.

//Pre-processor statements
#include "prog3Table.h"
using namespace std;

int main()
{

	//variables
	item toAdd, anItem;                      //A single item containing all data members of the item class
	table availableItems;                    //A list of items stored in the hash table data structure
	queue listOfItems, testList;             //A list of items stored in the queue data structure
	char name[100];                          //Name of an item, statically allocated
	char location[100];                      //Location of an item, statically allocated
	char hint[100];                          //Hint for an item, statically allocated
	int selection, response;                 //Lets the user input a reply for a menu option 

   
    //Import available items from external file	into the Hash Table
    if(!availableItems.readInFile(toAdd)) 
	    cout <<"Error loading from file" <<endl;

    do
    {
	   cout <<"Main Menu" <<endl;
	   cout <<"What would you like to do?"
	        <<"\n1. Test playing the game."
	        <<"\n2. Test the Queue data structure."
	        <<"\n3. Test the Hash Table data structure."
	        <<"\n4. Quit program." <<endl;
	   cout <<"Please make a selection by entering a number from 1 to 4. ";
	   cin >>selection; cin.ignore(100, '\n');
	   cout <<endl;

	   //PART 1: Testing the Game
	   if(selection == 1)
	   {
	       //Ask the user to build the scavenger hunt list
               cout <<"Let's begin by creating your custom scavenger hunt." <<endl <<endl;
	       cout <<"Please enter the names of the items you would like to add to your game."
	            <<"\n(See 'availableItems.txt' file for all available items)" <<endl;
               do
	       {
	           cin.get(name, 100, '\n'); cin.ignore(100, '\n');

		   if(!availableItems.retrieve(name, toAdd))
		   {
			   cout <<"This item is not available. Try again."
		                <<"\n(See 'availableItems.txt' file for all available items)" <<endl;
		   }
		
		   else
		   {
	               if(!toAdd.copy(name))
		           cout <<"Error. Did not add" <<endl;

                       if(!listOfItems.enqueue(toAdd))
		           cout <<"Error. Nothing to add." <<endl;
		   }
	       }while(again());


	       //Play the game
               cout <<"Great! You are ready to begin your custom Halloween scavenger hunt." <<endl <<endl;
	       do
               {
                   cout <<"Search for this item:" <<endl <<endl;
	           if(!listOfItems.peek(toAdd))
		        cout <<"Error. List is empty." <<endl;
       
                   //Links the two ADTs together. 	
                   if(!toAdd.transferName(toAdd,name))
		        cout <<"Error." <<endl;

	           //Display Item to search for
	           if(!availableItems.retrieve(name, toAdd))
		        cout <<"Error. No match was found." <<endl;
                   else 
	           {
	                if(!toAdd.display())
			     cout <<"Error. Unable to display item." <<endl;
	           }

	           //Ask if user would like a hint
	           cout <<"Enter 1 for a hint, enter any other number to move on to the next item.";
	           cin >>response; cin.ignore(100, '\n');
	           if(response == 1) 
	           {
		        if(!toAdd.displayHint())
			      cout <<"Error displaying hint." <<endl;
		        cout <<endl <<"Enter any number to move on to the next item.";
	                cin >>response; cin.ignore(100, '\n');
		        cout <<endl;
	           }

	           //Remove item from list once it has been found 
	           if(!listOfItems.dequeue())
		        cout <<"Error. Unable to remove from list." <<endl;
	      
	       }while(listOfItems.isEmpty());

	       //End the game
	       cout <<"Congratulations! You win!"
	            <<"\nEnter any number to go back to the main menu. ";
	       cin >>response; cin.ignore(100, '\n');
	       cout <<endl;
	}

 
	//PART 2: Testing the Queue data structure
        if(selection == 2)
	{
	       do
	       {
		   cout <<endl;
	           cout <<"Queue Testing Menu" <<endl <<endl;
	           cout <<"What would you like to test?"
	                <<"\n1. Add an item to the list." 
	                <<"\n2. Remove an item from the list."
	                <<"\n3. Display the first item on the list."
		        <<"\n4. Display all items in the list."
	                <<"\n5. Return to the main menu." <<endl;
	           cout <<"Please make a selection by entering a number from 1 to 5.";
	           cin >>response; cin.ignore(100, '\n');
	           cout <<endl;
	     
		   if(response == 1)
                   {
	               cout <<"Enter an item name you would like to add to the list." <<endl;
		       cin.get(name, 100, '\n'); cin.ignore(100, '\n'); 
	               if(!toAdd.copy(name))
		           cout <<"Error. Did not add" <<endl;
                       if(!testList.enqueue(toAdd))
		           cout <<"Error. Nothing to add." <<endl;
		    }

		    if(response == 2)
	            {
	               if(!testList.dequeue())
		           cout <<"Error. Unable to remove from list." <<endl;
		    }

		    if(response == 3)
		    {
	               if(!testList.peek(anItem))
		           cout <<"Error. List is empty." <<endl;
		       else
	               {
                           cout <<"The first item on the list is:" <<endl <<endl;
		           if(!anItem.display())
			       cout <<"Error. Cannot display. " <<endl;
		       }
		    }

		    if(response == 4)
		    {
	               if(!testList.displayAll())
			   cout <<"Error. Cannot display the list is empty." <<endl;
		    }

	        }while(response != 5);
	  }

	  //PART 3: Testing the Hash Table data structure
          if(selection == 3)
	  {
	        do
		{
		    cout <<endl;
	            cout <<"Hash Table Testing Menu" <<endl <<endl;
	            cout <<"What would you like to test?"
	                 <<"\n1. Add an item to the list." 
	                 <<"\n2. Remove an item from the list by the item name."
	                 <<"\n3. Retrieve and display the information about an item (using the name)."
		         <<"\n4. Display all information for a particular matching key."
			 <<"\n5. Display all saved items in the list."
	                 <<"\n6. Return to the main menu." <<endl;
	            cout <<"Please make a selection by entering a number from 1 to 6.";
	            cin >>response; cin.ignore(100, '\n');
	            cout <<endl;
		      

		    if(response == 1)
		    {
			 cout <<"Enter the name of the item" <<endl;
			 cin.get(name, 100, '\n'); cin.ignore(100, '\n');
			 cout <<"Enter the location of the item." <<endl;
			 cin.get(location, 100, '\n'); cin.ignore(100, '\n');
			 cout <<"Enter the hint about this item." <<endl;
			 cin.get(hint, 100, '\n'); cin.ignore(100, '\n');

	                 if(!toAdd.copyAll(name, location, hint))
		              cout <<"Error. Did not add" <<endl;

			 if(!availableItems.insert(name, toAdd))
			      cout <<"Error. Did not to the list of items." <<endl;
		     }

		     if(response == 2)
		     {
	                cout <<"Which item would you like to remove?" <<endl;
	                cin.get(name, 100, '\n'); cin.ignore(100, '\n');
	                if(!availableItems.remove(name))
		             cout <<"Unable to remove." <<endl;
		     }

		     if(response == 3)
		     {
	                  cout<<"Enter the name of the item to retrieve." <<endl;
	                  cin.get(name, 100, '\n'); cin.ignore(100, '\n');
	                  if(!availableItems.retrieve(name, anItem))
		              cout <<"No match was found." <<endl;
                          else 
                          {
	                      cout <<"The information found was: " <<endl;
	                      anItem.displayFull();
	                  }
		     }

		     if(response == 4)
		     {
	                  cout <<"Enter an item name to display key index." <<endl;
	                  cin.get(name, 100, '\n'); cin.ignore(100, '\n');
	                  if(!availableItems.displayByKey(name))
	                      cout <<"Nothing to display. Key index is empty." <<endl;
		     }

		     if(response == 5)
		     {
	                  if(!availableItems.displayInv())
		              cout <<"Error displaying" <<endl;
		     }

		}while(response != 6);
	 }

    }while(selection != 4);


   return 0;
}

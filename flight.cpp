#include <iostream>
#include <string>
using namespace std;


  class Flight
{

private:
int Flight_ID;
  
string Model;
  
int Capacity;
  
string Airline;
  
string Destination;
  
string Departure_Time;
  
double Ticket_Price;

 
public:
	
  Flight (int id, string model, int capacity, string airline,
			string destination, string departure,
			double price) 
:Flight_ID (id), Model (model),
	Capacity (capacity), Airline (airline), Destination (destination),
	Departure_Time (departure), Ticket_Price (price)
  {
  } 
 
	
  void setFlightID (int id)
  {
	Flight_ID = id;
  } 
void setModel (string model)
  {
	Model = model;
  } 

  int getFlightID () const
  {
	return Flight_ID;
  }
   
string getModel () const
  {
	return Model;
  }
   

  void displayFlightInfo () const
  {
	
cout << "Flight ID: " << Flight_ID << "\nModel: " << Model <<
	  "\nCapacity: " << Capacity 
 <<"\nAirline: " << Airline <<
	  "\nDestination: " << Destination << "\nDeparture Time: " <<
	  Departure_Time 
 <<"\nTicket Price: " << Ticket_Price << endl;

} 
};

  template < typename T > 
class Node
{

public:
T data;
  
Node * next;

 
Node (T value):data (value), next (nullptr)
  {
} 
};


 

  template < typename T > 
class FlightList
{

private:
Node < T > *head;

 
public: 
FlightList ():head (nullptr)
  {
  } 
 
	
  void addFlight (const T & flight)
  {
	
Node < T > *newNode = new Node < T > (flight);
	
Node < T > *temp = head;
	
bool IdChecker = true;
	
if (temp != NULL)
	  
	  {
		
while (temp)
		  {
			
if (temp->data.getFlightID () == flight.getFlightID ())
			  
			  {
				
IdChecker = false;
				
cout << "A flight with the same ID already exists";
				
break;
			  
}
			
 
temp = temp->next;
		  
}
	  
}
	
if (IdChecker)
	  
	  {
		if (!head)
		  {
			
head = newNode;
		  
}
		else
		  {
			
Node < T > *temp = head;
			
while (temp->next)
			  {
				
temp = temp->next;
			  
}
			
temp->next = newNode;
		  
}
		
cout << "Flight added successfully!\n";
	  
}
  
}
  
 
	
  void deleteFlight (int flightID)
  {
	
Node < T > *current = head;
	
Node < T > *prev = nullptr;
	
 
 
while (current != nullptr
				&& current->data.getFlightID () != flightID)
	  {
		
prev = current;
		
current = current->next;
	  
}
	
 
if (current == nullptr)
	  {
		
cout << "Flight not found.\n";
		
return;
	  
}
	
 
if (prev == nullptr)
	  {
		
		 
		  head = current->next;
	  
}
	else
	  {
		
		  
		  prev->next = current->next;
	  
}
	
 
delete current;
	
cout << "Flight deleted successfully!\n";
  
}
  
 
 
 
 
	
  void displayAll () const
  {
	
Node < T > *temp = head;
	
if (temp != NULL)
	  
	  {
		
while (temp)
		  {
			
temp->data.displayFlightInfo ();
			
temp = temp->next;
		  
}
	   
}
	 
	else
	   
	  {
		
cout << "No flights found";
	  
}
  
 
 
}

};


 

  template < typename T > 
class FlightStack
{

private:
Node < T > *top;

 
public: 
FlightStack ():top (nullptr)
  {
  }
  
 
	
  void pushFlight (const T & flight)
  {
	
Node < T > *newNode = new Node < T > (flight);
	
newNode->next = top;
	
top = newNode;
	
cout << "Flight pushed to the stack successfully!\n";
  
} 
 
	
  void printStack () const
  {
	
Node < T > *temp = top;
	
cout << "Stack Contents:\n";
	
while (temp != nullptr)
	  {
		
temp->data.displayFlightInfo ();
		
temp = temp->next;
	  
}
   
}
   

	
  void peek ()
  {
	
if (!this->isEmpty ())
	  {
		
this->top->data.displayFlightInfo ();
	  
}
	else
	  {
		
cout << "No flights found\n";
	  
}
  
}
  
 

  void popFlight (int flightID)
  {
	
if (top == nullptr)
	  {
		
cerr << "No flights found\n";
		
return;
	  
}
	
 
Node < T > *current = top;
	
if (current->data.getFlightID () == flightID)
	  {
		
top = top->next;
		
delete current;
		
cout << "Flight deleted successfully!\n";
		
return;
	  
}
	
 
Node < T > *prev = nullptr;
	
while (current != nullptr && current->data.getFlightID () != flightID)
	  {
		
prev = current;
		
current = current->next;
	  
}
	
 
if (current == nullptr)
	  {
		
cerr << "Flight not found in the stack.\n";
		
return;
	  
}
	
 
prev->next = current->next;
	
delete current;
	
cout << "Flight deleted successfully!\n";
  
}
  
 

  void editFlight (int flightID, const T & newFlight)
  {
	
Node < T > *current = top;
	
while (current != nullptr && current->data.getFlightID () != flightID)
	  {
		
current = current->next;
	  
}
	
 
if (current == nullptr)
	  {
		
cerr << "Flight not found in the stack\n";
		
return;
	  
}
	
 
current->data = newFlight;
	
cout << "Flight edited successfully!\n";
  
}
  
bool containsFlight (int flightID) const
  {
	
Node < T > *temp = top;
	
while (temp != nullptr)
	  {
		
if (temp->data.getFlightID () == flightID)
		  {
			
return true;		
		  }
		 
temp = temp->next;
	  
}
	
return false;				
  }
  
 
	
  bool isEmpty () const
  {
	
return top == nullptr;
  
}
 


};


  int
main ()
{
  
cout << "Welcome to the Flight Management System!" << endl;
  
 
	
	FlightList < Flight > flightList;
  

	FlightStack < Flight > flightStack;
  
 
while (true)
	{
	  
cout << "\nChoose an option:\n";
	  
cout << "1. LinkedList\n";
	  
cout << "2. Stack\n";
	  
int option;
	  
cin >> option;
	  
 
if (option == 1)
		{
		  
cout << "\nLinkedList Options:\n";
		  
cout << "1. Insert new flight\n";
		  
cout << "2. Delete Flight\n";
		  
cout << "3. Show latest flight\n";
		  
cout << "4. Display All Flights\n";
		  
cout << "5. Close the program\n";
		  
 
int linkedListOption;
		  
cin >> linkedListOption;
		  
 
switch (linkedListOption)
			{
			
case 1:
			  {
				
				  
				int id;
				
string model;
				
int capacity;
				
string airline;
				
string destination;
				
string departure;
				
double price;
				
 
cout << "Enter Flight ID: ";
				
cin >> id;
				
cout << "Enter Model: ";
				
cin.ignore ();
				
getline (cin, model);
				
cout << "Enter Capacity: ";
				
cin >> capacity;
				
cout << "Enter Airline: ";
				
cin.ignore ();
				
getline (cin, airline);
				
cout << "Enter Destination: ";
				
cin.ignore ();
				
getline (cin, destination);
				
cout << "Enter Departure Time: ";
				
getline (cin, departure);
				
cout << "Enter Ticket Price: ";
				
cin >> price;
				
 
Flight newFlight (id, model, capacity, airline,
									 destination, departure, price);
				
flightList.addFlight (newFlight);
				
 
break;
			  
}
			
case 2:
			  {
				
				  
				int idToDelete;
				
cout << "Enter Flight ID to delete: ";
				
cin >> idToDelete;
				
				  
				  flightList.deleteFlight (idToDelete);
				
 
break;
			  
}
			
case 3:
			  {
				
flightStack.peek ();
				
break;
			  
}
			
case 4:
			  {
				
				  
				  flightList.displayAll ();
				
break;
			  
}
			
case 5:
			  {
				
				  
				  cout << "Exiting program...\n";
				
return 0;
			  
}
			
default:
			  
cout << "Invalid option. Please try again.\n";
			
}
		
}
	  else if (option == 2)
		{
		  
cout << "\n Stack Options:\n";
		  
cout << "1. Insert new flight\n";
		  
cout << "2. Delete Flight\n";
		  
cout << "3. edit Flight\n";
		  
cout << "4. Show latest Flight\n";
		  
cout << "5. Display All Flights\n";
		  
cout << "6. Close the program\n";
		  
 
int stackOption;
		  
cin >> stackOption;
		  
 
switch (stackOption)
			{
			
 
case 1:
			  {
				
 
 
				  
				int id;
				
string model;
				
int capacity;
				
string airline;
				
string destination;
				
string departure;
				
double price;
				
 
cout << "Enter Flight ID: ";
				
cin >> id;
				
cout << "Enter Model: ";
				
cin.ignore ();
				
getline (cin, model);
				
cout << "Enter Capacity: ";
				
cin >> capacity;
				
cout << "Enter Airline: ";
				
cin.ignore ();
				
getline (cin, airline);
				
cout << "Enter Destination: ";
				
cin.ignore ();
				
getline (cin, destination);
				
cout << "Enter Departure Time: ";
				
getline (cin, departure);
				
cout << "Enter Ticket Price: ";
				
cin >> price;
				
 
Flight newFlight (id, model, capacity, airline,
									 destination, departure, price);
				
flightStack.pushFlight (newFlight);
				
 
break;
			  
}
			
case 2:
			  {
				
				  
				int idToDelete;
				
cout << "Enter Flight ID to delete: ";
				
cin >> idToDelete;
				
				  
				  flightStack.popFlight (idToDelete);
				
break;
			  
}
			
case 3:
			  {
				
int idToEdit;
				
cout << "Enter Flight ID to edit: ";
				
cin >> idToEdit;
				
 
bool idChecker = flightStack.containsFlight (idToEdit);
				
 
if (idChecker)
				  
				  {
					int id;
					
string model;
					
int capacity;
					
string airline;
					
string destination;
					
string departure;
					
double price;
					
cout << "Enter new Flight data: \n";
					
 
cout << "Enter Flight ID: ";
					
cin >> id;
					
cout << "Enter Model: ";
					
cin.ignore ();
					
getline (cin, model);
					
cout << "Enter Capacity: ";
					
cin >> capacity;
					
cout << "Enter Airline: ";
					
cin.ignore ();
					
getline (cin, airline);
					
cout << "Enter Destination: ";
					
cin.ignore ();
					
getline (cin, destination);
					
cout << "Enter Departure Time: ";
					
getline (cin, departure);
					
cout << "Enter Ticket Price: ";
					
cin >> price;
					
 
Flight editedFlight (id, model, capacity, airline,
											destination, departure, price);
					
flightStack.editFlight (idToEdit, editedFlight);
				  
}
				
				else if (flightStack.isEmpty ())
				  
				  {
					
cout << "Stack is empty";
				  
}
				
				else
				  {
					
cout << "Flight does not exist";
				  
}
				
 
break;
			  
}
			
case 4:
			  {
				
				 
				  flightStack.peek ();
				
break;
			  
}
			
case 5:
			  {
				
				 
				  flightStack.printStack ();
				
break;
			  
}
			
case 6:
			  {
				
				 
				  cout << "Exiting program...\n";
				
return 0;
			  
}
			
default:
			  
cout << "Invalid option. Please try again.\n";
			
}
		
}
	  else
		{
		  
cout << "Invalid option. Please try again.\n";
		
}
	
}
  
 
return 0;

}


/************************************************************************************************************************
File Name: vlist.cpp
Name: Luis Gustavo Grubert Valensuela Z#:23351882 lvalensuela2015@fau.edu
Course: Data Struct/Algorithm (COP3530-003)
Professor: Dr. Lofton Bullard
Due Date:03/27/2017             Due Time: 11:30PM
Total Points: 25
Assignment Number Unit 9 - Programming Assingment
Last Changed: 04/10/2017

Description:
In this assignment a class vlist will be implemented.
This class will have a string vector that will be manipulated through iterators.
/************************************************************************************************************************/

#include "vlist.h"

using namespace std;

//*************************************************************************************
//Name: vlist() (Default Constructor)
//Precondition: None
//Postcondition: An empty vector<string>
//Description:   An empty vector<string>
//
//*************************************************************************************
vlist::vlist()
{
	cout << "Default Constructor Invoked\n";
	vector<string> DB;

}

//*************************************************************************************
//Name: vlist(vlist & original) (Copy Constructor)
//Precondition: None
//Postcondition: Creates a deep copy of the object vlist with its vector<string>
//Description:   Creates a deep copy of the object vlist with its vector<string>
//
//*************************************************************************************
vlist::vlist(vlist & original)
{
	cout << "Copy Constructor Invoked\n";
	DB = original.DB;
	cout << "Printing the content of the original object (Right hand side of = operator)\n";
	original.print();
	cout << "Printing the content of the new copied object (Left hand side of = operator)\n";
	(*this).print();
}

//*************************************************************************************
//Name: ~vlist() (Destructor)
//Precondition: a vlist object has been created.
//Postcondition: Erases the vector<string>
//Description:   Erases the vector<string>
//
//*************************************************************************************
vlist::~vlist()
{
	cout << "Default Destructor Invoked\n";
	DB.clear();
}

//*************************************************************************************
//Name: isEmpty()
//Precondition: a vlist object has been created.
//Postcondition: Returns true if the vlist has a empty vector<string>
//Description:   Returns true if the vlist has a empty vector<string>
//
//*************************************************************************************
bool vlist::isEmpty() {
	return DB.empty();
}

//*************************************************************************************
//Name: Print()
//Precondition: a vlist object has been created.
//Postcondition: Print all the elements of the vlist object, vector<string>, one per line.
//Description:   Print all the elements of the vlist object, vector<string>, one per line.
//
//*************************************************************************************
void vlist::print()
{
	for (it = DB.begin(); it != DB.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
}

//*************************************************************************************
//Name: insert(const string &key)
//Precondition: a vlist object has been created.
//Postcondition: Inserts a string to the vector<string> element from vlist object
//Description:   Inserts a string to the vector<string> element from vlist object
//
//*************************************************************************************
void vlist::insert(const string &key)
{
	DB.push_back(key);
	sort(DB.begin(), DB.end());
}

//*************************************************************************************
//Name: vlist::remove(const string &key)
//Precondition: a vlist object has been created.
//Postcondition: Removes a string key from the vector<string> element from vlist object. 
//				 If vector is empty of the string key was not found, a message will be displayed.
//Description:   Removes a string key from the vector<string> element from vlist object. 
//				 If vector is empty of the string key was not found, a message will be displayed.
//
//*************************************************************************************
void vlist::remove(const string &key)
{
	if (!isEmpty())
	{
		it = search(key);
		if (it != DB.end())
		{
			DB.erase(it);
			cout << " Was removed from the list\n";
		}
		else {
			cout << " Was not removed from the list\n";
		}
	}
	else
	{
		cout << "The list is empty, nothing was removed\n";
	}

}

//*************************************************************************************
//Name: vlist::search(const string & key)
//Precondition: a vlist object has been created.
//Postcondition: Searches for a string key from the vector<string> element from vlist object. 
//				 If vector is empty of the string key was not found, a message will be displayed.
//Description:   Searches for a string key from the vector<string> element from vlist object. 
//				 If vector is empty of the string key was not found, a message will be displayed.
//
//*************************************************************************************
vector<string>::iterator vlist::search(const string & key)
{
	it2 = find(DB.begin(), DB.end(), key);


	//return vector<string>::iterator();
	if (it2 == DB.end())
	{
		cout << "Item " << key << " Not Found.";
		return it2;
	}
	else
	{
		cout << "Item " << key << " Found.";
		return it2;
	}
}


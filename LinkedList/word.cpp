
/************************************************************************************************************************
File Name: word.cpp
Name: Luis Gustavo Grubert Valensuela Z#:23351882 lvalensuela2015@fau.edu
Course: Data Struct/Algorithm (COP3530-003)
Professor: Dr. Lofton Bullard
Due Date:03/01/2017             Due Time: 11:30PM
Total Points: 25
Assignment Number Unit 6 - Programming Assingment
Last Changed: 02/28/2017

Description:
In this assignment a class word will be created.
This class will have a linked list which nodes will be of type char.
The class character will be responsible to deal with the node, and
the class word will be responsible to deal with the list itselfe that
will have two pointers of the type "character": one front that points to
the fist elemento of the list, and back that poits to the end of the list
/************************************************************************************************************************/

#include <iostream>
#include <string>
#include "word.h"

using namespace std;

//*************************************************************************************
//Name:Length()
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: returns the length of the list, 0 case the list is empty.
//Description:  returns the length of the list, 0 case the list is empty.
//
//*************************************************************************************
int WORD::Length()
{
	if (front == 0)
	{
		return 0;
	}
	else
	{
		character *p = front;
		int count = 0;

		while (p != 0)
		{
			count++;
			p = p->next;
		}
		return count;
	}
}

//*************************************************************************************
//Name: WORD (Default Constructor)
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to an empty list
//Description:  This is the default constructor which will be called automatically when
//an object is declared.  It will initialize the state of the class to an empty list
//
//*************************************************************************************
WORD::WORD()
{
	cout << "Inside the default constructor\n";
	front = back = 0;

}

//*************************************************************************************
//Name: WORD (Copy Constructor)
//Precondition: the object org has been initialized 
//Postcondition: a depy copy or the object org has been done.
//Description:  This is the copy constructor which will be called automatically when
//needed. It will make a deep copy of the object org.
//
//*************************************************************************************
WORD::WORD(const WORD & org)
{
	cout << "Inside the copy constructor\n";
	CreateList(org);
}

//*************************************************************************************
//Name: WORD (Explicity-value Constructor)
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to a list with string s
//Description:  This is the explicity-value constructor which will be called automatically when
//an object is declared.  It will initialize the state of the class with a list
//that has the string s as content.
//
//*************************************************************************************
WORD::WORD(const string & s)
{
	cout << "Inside the explicity constructor";

	//deleting the previously list;
	while (front != 0)
	{
		character *p = front;
		front = front->next;
		delete p;
	}

	for (int i = 0; i < s.length(); i++)
	{
		InsertSymbol(s[i]);
	}
}

//*************************************************************************************
//Name:  = overload.
//Precondition: an object of type word has been created.
//Postcondition: the current object will have the list values from the object w
//Description: the current object will have the list values from the object w
//*************************************************************************************
void WORD::operator=(const string & s)
{
	//deleting the previously list;
	while (front != 0)
	{
		character *p = front;
		front = front->next;
		delete p;
	}

	for (int i = 0; i < s.length(); i++)
	{
		InsertSymbol(s[i]);
	}
}

//*************************************************************************************
//Name:  = overload with chainning.
//Precondition: an object of type word has been created.
//Postcondition: the current object will have the list values from the object w and the
// calling object will be returned
//Description: the current object will have the list values from the object w and the
// calling object will be returned
//*************************************************************************************
WORD & WORD::operator=(const WORD & w)
{
	cout << "operator = ";
	//deleting the previously list;
	while (front != 0)
	{
		character *p = front;
		front = front->next;
		delete p;
	}
	CreateList(w);
	return *this;
}

//*************************************************************************************
//Name:  ~WORD default deconstructor
//Precondition: an object of type word has been created.
//Postcondition: deletes all the list elements of the word object until it have the 
// pointers front and back iqual to 0
//Description: deletes all the list elements of the word object until it have the 
// pointers front and back iqual to 0
//*************************************************************************************
WORD::~WORD()
{
	cout << "Destructor has been called\n";
	while (front != 0)
	{
		character *p = front;
		front = front->next;
		delete p;
	}
}

//*************************************************************************************
//Name:  << overload
//Precondition: an object of type word has been created.
//Postcondition: Outputs the word nodes 
//Description:Outputs the word notes or the message "The list is empty" case the list 
//is empty.
//*************************************************************************************
ostream & operator<<(ostream & out, const WORD & obj)
{
	if (!obj.front == 0)
	{
		//out << "<< overloaded" << endl;
		character *p = obj.front;

		while (p != 0)
		{
			out << p->symbol;
			p = p->next;
		}
	}
	else
	{
		out << "The list is empty" << endl;
	}
	return out;
}

//*************************************************************************************
//Name:  IsEqual()
//Precondition: an object of type word has been created.
//Postcondition: Outputs true of false case the calling object is equal or not to the 
// object B
//Description:Outputs true of false case the calling object is equal or not to the 
// object WORD B
//*************************************************************************************
bool WORD::IsEqual(const WORD & B)
{
	int equal = 1;
	character *p = front;
	character *p2 = B.front;

	while (p != 0)
	{
		if (p->symbol != p2->symbol)
		{
			equal = 0;
			break;
		}
		p = p->next;
		p2 = p2->next;
	}
	return equal;
}

//*************************************************************************************
//Name:  + overload
//Precondition: an object of type word has been created.
//Postcondition: the current object has its original list value added to the list of the 
// object B
//Description: the current object has its original list value added to the list of the 
// object B
//*************************************************************************************
void WORD::operator+(const WORD & B)
{
	//CreateList(B);
	character *p2 = B.front;
	while (p2 != 0)
	{
		character *p3 = new character;
		p3->symbol = p2->symbol;
		p3->next = 0;
		if (IsEmpty())
		{
			front = p3;
			back = p3;
		}
		else
		{
			back->next = p3;
			back = p3;
		}
		p2 = p2->next;
	}
}

//*************************************************************************************
//Name:CreateList
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: Creates a list with the content of the object Word Org. 
//Description:  Creates a list with the content of the object Word Org. 
//
//*************************************************************************************
void WORD::CreateList(const WORD & Org)
{
	if (Org.front == 0)
	{
		back = front = 0;
	}
	else
	{
		character *p = Org.front;
		while (p != 0)
		{
			InsertSymbol(p->symbol);
			p = p->next;
		}
	}
}

//*************************************************************************************
//Name:InsertSymbol
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: Insert a characgter ch into the nodes. 
//Description:  Insert a characgter ch into the nodes.  
//
//*************************************************************************************
void WORD::InsertSymbol(char ch)
{
	character *p = new character;
	p->symbol = ch;
	p->next = 0;

	if (front == 0)
	{
		front = back = p;
	}
	else
	{
		back->next = p;
		back = p;
	}
}


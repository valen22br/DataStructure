
/************************************************************************************************************************
File Name: word.h
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
#pragma once
#include <iostream>
#include <string>


using namespace std;

#ifndef WORD_H
#define WORD_H

class character
{
public:
	char symbol;
	character *next;
};

class WORD
{
public:
	bool IsEmpty() { return front == 0; }
	int Length(); //Length: Determines the length of the word A; remember A is the current object;
	friend ostream & operator<<(ostream & out, const WORD & obj);  //Overload the insertion operator as a friend function with chaining to print a word A;
	void operator=(const string & s); //{} Overload the assignment operator as a member function to take a 
									   //string (C-style or C++ string, just be consistent in your implementation) as an argument and 
									   //assigns its value to A, the current object;
	WORD & operator=(const WORD & w); //{ WORD k; return k; } // Overload the assignment operator as a member function with chaining to take a word 
														   //object as an argument and assigns its value to A, the current object;
	void operator+(const WORD & B); //{} Overload the ë+î operator as a member function without chaining to add word B 
									  //(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A; 
									  //remember A is the current object;
	WORD(); //{ front = back = 0; }    The default constructor will initialize your state variables. 
									 //The front of the linked list is initially set to NULL or 0; this implies a non-header node 
									 //implementation of the link list.
	WORD(const string & s); //{ } //Explicit-value constructor: This constructor will have one argument; 
							   //a C-style string or a C++ string representing the word to be created;
	WORD(const WORD & org); //{}   // Copy Constructor: Used during a call by value, return, or initialization/declaration of a word object;
	~WORD(); //{}                   //Destructor: The destructor will de-allocate all memory allocated for the word. Put the message 
								 //"destructor called\n" inside the body of the destructor.
	bool IsEqual(const WORD & B); // Returns true if two word objects are equal; otherwise false; remember A is the current
	void CreateList(const WORD & Org);
	void InsertSymbol(char ch);

private:
	character *front, *back;
};

#endif


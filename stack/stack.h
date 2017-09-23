
/************************************************************************************************************************
File Name: stack.h
Name: Luis Gustavo Grubert Valensuela Z#:23351882 lvalensuela2015@fau.edu
Course: Data Struct/Algorithm (COP3530-003)
Professor: Dr. Lofton Bullard
Due Date:03/13/2017             Due Time: 11:30PM
Total Points: 25
Assignment Number Unit 7 - Programming Assingment
Last Changed: 03/13/2017

Description:
In this assignment a class stack will be implemented.
This class will have stack with linked list which nodes will be of type string.
The class stack_node will be responsible to deal with the node, and
the class stack will be responsible to deal with the stack itselfe that
will have on ponter to the top. The last node will be a null pointer.
The main function will prompt the user for a postfix strings and will display
an infix expresion.
/************************************************************************************************************************/

#pragma once
#ifndef STACK

#include<iostream>
#include<string>

using namespace std;

typedef string stack_element;

class stack_node
{
public:
	stack_element data;
	stack_node *next;
};

class stack
{
public:
	stack() { cout << "Inside Default Constructor \n"; s_top = 0; }
	~stack();
	stack(const stack & original);
	stack_element top();
	void pop();
	void push(const stack_element & value);
	void print();
	const stack & operator=(const stack & rightHandSide);
	bool isEmpty() const;

private:
	stack_node *s_top;
};


#endif // !STACK



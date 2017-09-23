
/************************************************************************************************************************
File Name: stack.cpp
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

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

//*************************************************************************************
//Name: stack (Copy Constructor)
//Precondition: the object original has been initialized 
//Postcondition: a deep copy or the object org has been done.
//Description:  This is the copy constructor which will be called automatically when
//needed. It will make a deep copy of the object org.
//
//*************************************************************************************
stack::stack(const stack & original)
{
	cout << "Inside CopyConstructor \n";
	stack_node *p = original.s_top;

	(*this).s_top = 0;
	while (p != 0)
	{
		(*this).push(p->data);
		p = p->next;
	}
}

//*************************************************************************************
//Name:  ~stack default deconstructor
//Precondition: an object of type stack has been created.
//Postcondition: deletes all the stack nodes elements of the stack object until it have the 
// pointer s_top equal to 0
//Description: deletes all the stack nodes elements of the stack object until it have the 
// pointer s_top equal to 0
//*************************************************************************************
stack::~stack()
{
	while (s_top != 0)
	{
		pop();
	}
}

//*************************************************************************************
//Name:  pop
//Precondition: an object of type stack has been created.
//Postcondition: pops an stack_element type node from the top of the stack.
//Description: pops an stack_element type node from the top of the stack.
//*************************************************************************************
void stack::pop()
{
	cout << "Inside pop\n";
	stack_node *p;
	if (s_top != 0)
	{
		p = s_top;
		s_top = s_top->next;
		delete p;
	}
}

//*************************************************************************************
//Name:  push
//Precondition: an object of type stack has been created.
//Postcondition: pushes an stack_element type on the top of the stack.
//Description: pushes an stack_element type on the top of the stack.
//*************************************************************************************
void stack::push(const stack_element & value)
{
	cout << "Inside push \n";
	stack_node *p = new stack_node;
	p->data = value;
	p->next = s_top;
	s_top = p;
}

//*************************************************************************************
//Name:  prints
//Precondition: an object of type stack has been created.
//Postcondition: Display all elements of the stack one on each line.
//Description: Display all elements of the stack one on each line.
//*************************************************************************************
void stack::print()
{
	cout << "Inside print \n";
	for (stack_node *p = s_top; p != 0; p = p->next)
	{
		cout << p->data << endl;
	}
}

//*************************************************************************************
//Name:  top
//Precondition: an object of type stack has been created.
//Postcondition: returns the data portion of the first node of the stack.
//Description: returns the data portion of the first node of the stack.
//*************************************************************************************
stack_element stack::top()
{
	cout << "Inside Top() \n";
	if (s_top == 0)
	{
		exit(1);
	}
	else
	{
		return s_top->data;
	}
}

//*************************************************************************************
//Name:  = overload with chainning.
//Precondition: an object of type stack has been created.
//Postcondition: the current object will have the stack values from the object rightHandSide
//and the calling object will be returned
//Description:  the current object will have the stack values from the object rightHandSide
//and the calling object will be returned
//*************************************************************************************
const stack & stack::operator=(const stack & rightHandSide)
{
	cout << "Inside Overloade Operator = \n";
	if (this != &rightHandSide)
	{
		(*this).~stack();
		if (rightHandSide.s_top == 0)
		{
			s_top = 0;
		}
		else
		{
			s_top = 0;
			stack_node *p = rightHandSide.s_top;
			while (p != 0)
			{
				(*this).push(p->data);
				p = p->next;
			}
		}
	}
	return *this;
}

//*************************************************************************************
//Name:  isEmpty
//Precondition: an object of type stack has been created.
//Postcondition: returns true is the stack is empty; otherwise returns false.
//Description: returns true is the stack is empty; otherwise returns false.
//*************************************************************************************
bool stack::isEmpty() const
{
	return s_top == 0;
}

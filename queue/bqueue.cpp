
/************************************************************************************************************************
File Name: bqueue.cpp
Name: Luis Gustavo Grubert Valensuela Z#:23351882 lvalensuela2015@fau.edu
Course: Data Struct/Algorithm (COP3530-003)
Professor: Dr. Lofton Bullard
Due Date:03/27/2017             Due Time: 11:30PM
Total Points: 25
Assignment Number Unit 8 - Programming Assingment
Last Changed: 03/27/2017

Description:
In this assignment a class BQUEUE will be implemented.
This class will have doubly-linked ciruclar queue which nodes that will hold integers values..
The class bqnode is responsible to deal with the node, and
the class BQUEUE will be responsible to deal with the doubly-linked circular queue itselfe that
will have one pointer front that will point to the first and alto to the last element.
The last node will point to the first node (front) as well.
/************************************************************************************************************************/

#include "bqueue.h"
#include <iostream>

using namespace std;

//*************************************************************************************
//Name: BQUEUE (Default Constructor)
//Precondition: None
//Postcondition: An empty queue will create with the front pointer initialized to 0(null)
//Description:   An empty queue will create with the front pointer initialized to 0(null)
//
//*************************************************************************************
BQUEUE::BQUEUE() :front(0)
{}

//*************************************************************************************
//Name:  ~BQUEUE default deconstructor
//Precondition: an object of type BQUEUE has been created.
//Postcondition: deletes all the DOUBLY-LINKED CIRCULAR QUEUE nodes elements of the queue object until it have the 
// no more pointers.
//Description: deletes all the stack nodes elements of the stack object until it have the 
// pointer s_top equal to 0
//*************************************************************************************
BQUEUE::~BQUEUE()
{
	cout << " ~QUEUE has been called\n";
	while (!empty())
	{
		Dequeue();
	}
}
//*************************************************************************************
//Name: BQUEUE (Copy Constructor)
//Precondition: the object original has been initialized 
//Postcondition: a deep copy or the object original has been done.
//Description:  This is the copy constructor which will be called automatically when
//needed. It will make a deep copy of the object original.
//
//*************************************************************************************
BQUEUE::BQUEUE(const BQUEUE & original)
{
	cout << "Inside Copy Constructor: \n";
	if (!original.empty())
	{
		(*this).~BQUEUE();
		bqnode *p = original.front;
		do
		{
			Enqueue(p->time);
			p = p->next;
		} while (p != original.front);
	}
	else
	{
		(*this).~BQUEUE();
	}
}

//*************************************************************************************
//Name:  Enqueue(int a)
//Precondition: an object of type BQUEUE has been created.
//Postcondition: pushes an int element to the end of the queue.
//Description: pushes an int element to the end of the queue.
//*************************************************************************************
void BQUEUE::Enqueue(int a)
{
	bqnode *p = new bqnode;

	if (!empty())
	{
		if (front->prev !=0 && front->prev == front)
		{
			front->prev = p;
			front->prev->prev = front;
			front->prev->next = front;
			front->next = p;
		}
		else
		{
			front->prev->next = p;
			front->prev->next->prev = front->prev;
			front->prev->next->next = front;
			front->prev = p;
		}
		p->time = a;
	}
	else
	{
		front =  p;
		front->next = front->prev = p;
		front->time = a;
	}
}

//*************************************************************************************
//Name:  Dequeue()
//Precondition: an object of type BQUEUE has been created.
//Postcondition: removes an int element from the beginning of the queue.
//Description: removes an int element from the beginning of the queue.
//*************************************************************************************
void BQUEUE::Dequeue()
{
	if (!empty())
	{
		bqnode *p;
		p = front;
		if (front->prev == front)//one node only
		{
			front = 0;
			delete p;
		}
		else
		{
			front->prev->next = front->next;
			front->next->prev = front->prev;
			front = front->next;

			delete p;
		}
	}
	else
	{
		cout << endl << "The queue is empty, nothing to remove"<< endl;
	}
}

//*************************************************************************************
//Name:  Front()
//Precondition: an object of type BQUEUE has been created.
//Postcondition: returns the first element of the front of the queue, without changing it.
//Description: returns the first element of the front of the queue, without changing it.
//*************************************************************************************
int & BQUEUE::Front()
{
	int i = -1;
	if (!empty())
	{
		return front->time;
	}
	else
	{
		cout << endl << "Queue is empty, no front element to be displayed. -1 Will be the value returned by the function." << endl;
		return i;
	}
}

//*************************************************************************************
//Name:  Print()
//Precondition: an object of type BQUEUE has been created.
//Postcondition: Display all elements of the QUEUE, fron front to back.
//Description: Display all elements of the QUEUE, fron front to back.
void BQUEUE::Print()
{
	if (!empty())
	{
		cout << endl;
	bqnode *p = front;
	do
	{
		cout << p->time << endl;;
		p = p->next;
	} while (p != front);
}
	else
	{
		cout << endl << "Queue is Empty. Nothing to be printed." << endl;
	}

}


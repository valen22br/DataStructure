
/************************************************************************************************************************
File Name: bqueue.h
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
#pragma once
#ifndef BQUEUE
#include<iostream>

using namespace std;

class bqnode{
public:
	int time;
	bqnode * prev, *next;
	bqnode::bqnode() { prev = 0; next = 0; }
};

class BQUEUE {
public:
	BQUEUE();
	~BQUEUE();
	BQUEUE(const BQUEUE &);
	void Enqueue(int);
	void Dequeue();
	void Print();
	bool empty() const { return front == 0; }
	int & Front();

private:
	bqnode * front;
};
#endif // !BQUEUE

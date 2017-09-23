
/************************************************************************************************************************
File Name: BEQUEUE_driver.cpp
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

#include <iostream>
#include <string>
#include "bqueue.h"

using namespace std;

int main()
{

	//BQUEUE Q;
	////BQUEUE R = Q;

	////Q.deQueue();

	//Q.enQueue(1);
	//Q.enQueue(2);
	//Q.enQueue(3);
	//Q.enQueue(4);
	//Q.enQueue(5);

	//BQUEUE R = Q;

	//Q.Print();
	//cout << endl;
	//Q.deQueue();
	//cout << Q.Front() << endl;
	//cout << endl;
	//Q.Print();
	//cout << endl;
	//Q.deQueue();
	//Q.deQueue();
	//cout << endl;
	//Q.Print();

	//Q.deQueue();
	//Q.deQueue();
	//Q.deQueue();
	//cout << endl;
	//Q.Print();

	//cout << "R Queue"<< endl;
	//R.Print();

	BQUEUE k;
	k.Enqueue(60);
	k.Print();
	k.Enqueue(20);
	k.Enqueue(30);
	k.Print();
	k.Enqueue(10);
	k.Print();
	k.Enqueue(50);
	k.Enqueue(40);

	BQUEUE j = k;

	cout << endl;
	j.Print();
	cout << endl;


	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();

	cout << endl << "___" << endl;
	k.Front();
	cout << endl;
	cout << "J front=> " << j.Front() << endl;;
	cout << "k front=> " << k.Front() << endl;;




	//BQUEUE Q;

	//Q.Dequeue();

	//Q.Enqueue(1);
	//Q.Enqueue(2);
	//Q.Enqueue(3);
	//Q.Enqueue(4);
	//Q.Enqueue(5);
	//Q.Print();
	//cout<<Q.Front()<<endl;
	//Q.Dequeue();
	//cout<<Q.Front()<<endl;
	//Q.Dequeue();
	//Q.Dequeue();
	//cout << "***" << endl;
	//Q.Print();


	//Q.Dequeue();
	//Q.Dequeue();
	//cout << "***" << endl;
	//Q.Print();

	//Q.Dequeue();
	//Q.Dequeue();
	//cout << "***" << endl;
	//Q.Print();


	return 0;
}

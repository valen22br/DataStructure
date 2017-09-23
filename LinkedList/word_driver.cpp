
/************************************************************************************************************************
File Name: word.driver.cpp
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

int main()
{

	WORD you;
	cout << "************TEST#1*******************************\n";
	cout << "Testing the default constructor and printing empty word\n";
	cout << you << endl;
	cout << "The length of you is " << you.Length() << "= 0\n";
	cout << "*************************************************\n";
	cout << endl << endl;


	cout << "************TEST#2*******************************\n";
	WORD me("AAAA0000AAA0000AAA");
	cout << "Testing the explicit-value constructor\n";
	cout << me << endl;
	cout << "me is \n" << me << "= AAAA0000AAA0000AAA\n";

	cout << "The length of me is " << me.Length() << "= 0\n";

	cout << "*************************************************\n";
	cout << endl << endl;


	cout << "************TEST#3*******************************\n";
	WORD them = me;
	cout << "Testing the copy constructor\n";
	cout << "them is \n" << them << "= AAAA0000AAA0000AAA\n";
	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#4*******************************\n";
	cout << "Testing length\n";
	cout << "The length of me is " << me.Length() << " = 18 " << endl;
	cout << "The length of them is " << them.Length() << " = 18 " << endl;
	cout << "The length of you is " << you.Length() << " = 0 " << endl;
	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#5*******************************\n";
	WORD us;
	us = "AA";
	cout << "Testing operator= by assignment the value of \"AA\" to use\n";
	cout << "The word us is \n" << us << " = AA" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#6*******************************\n";
	WORD everyone = "hello world\n";
	cout << "Testing operator= by assignment the value of \"hello world\" to use\n";
	cout << "The word everyone is \n" << everyone << " = hello world" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;


	cout << "************TEST#7*******************************\n";
	WORD our, him;

	our = "AAA000AAA000";
	us = "XXXX";

	cout << our << endl;
	cout << us << endl;

	cout << "Testing IsEqual by testing to see inf us is equal to our \n";
	if (our.IsEqual(us))
		cout << "The 2 words are equal\n";
	else
		cout << "The 2 words are not equal\n";

	cout << "TEST SHOULD REVEAL THAT our AND us are not equal\n";

	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#8*******************************\n";
	cout << "Adding 2 words by adding us to the back of their.  Their is the current object \n";
	WORD their("AAAA0000AAA0000AAA");
	cout << endl << "their- " << their << endl;
	cout << "us- " << us << endl;
	their + us;
	cout << "their followed by us is \n" << their << " = AAAA0000AAA0000AAAXXXX" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#9*******************************\n";
	cout << "Adding 2 words, their2 is empty, by adding us to the back of their.  Their is the current object \n";
	WORD their2("");
	cout << endl << "their2- " << their2 << endl;
	cout << "us- " << us << endl;
	their2 + us;
	cout << "their followed by us is \n" << their2 << " = XXXX" << endl;
	cout << "*************************************************\n";

	cout << "************TEST#10*******************************\n";
	cout << "Adding 2 words, their3 is empty, by adding us to the back of their.  Their is the current object \n";
	WORD their3("");

	cout << endl << "their3- " << their3 << endl;
	cout << "us- " << us << endl;

	us + their3;
	cout << "us followed by empty their3 is \n" << us << " = XXXX" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;
	cout << endl << endl;

	cout << "************TEST#11*******************************\n";
	cout << "overloading = with chaining \n";
	WORD guti("abc");
	WORD guti2("ABC");
	WORD guti3 = "FinalTest";

	cout << endl << guti << endl << guti2 << endl;
	guti = guti2 = guti3;
	cout << "The word guti is \n" << guti << " = FinalTest" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;
	cout << endl << endl;

	return 0;
}

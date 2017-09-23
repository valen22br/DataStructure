
/************************************************************************************************************************
File Name: vlist_driver.cpp
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
int main() {


	//Testing default constructor
	cout << "Test1:Testing the default constructor for string\n";
	vlist String_List;
	//Testing functionality for string list 
	cout << "Test2: Testing Insert \n";
	String_List.insert("Hello");
	String_List.insert("Zebra");
	String_List.insert("Good_Bye");
	String_List.insert("Space");
	String_List.insert("No_One");
	String_List.print();
	cout << "Test 3: Testing copy constructor for string \n"; 
	vlist Copied_String = String_List;

	String_List.remove("Zebra");

	Copied_String.print();
	String_List.print();

	cout << "Test 4: Testing Remove for string \n"; 
	cout << "Testing Search and IsEmpty also\n"; 
	String_List.remove("Zebra");

	String_List.remove("Zebra");

	String_List.remove("Good_Bye"); 
	String_List.remove("Hello"); 
	String_List.remove("No_One"); 
	String_List.remove("Space"); 
	String_List.remove("Hello");
	cout << "When leave main destructor will be called" << endl;

	return 0;
}

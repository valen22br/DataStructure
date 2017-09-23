
/************************************************************************************************************************
File Name: vlist.h
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

#pragma once
#ifndef VLIST

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class vlist {
public:
	vlist();
	vlist(vlist &);
	~vlist();
	bool isEmpty();
	vector<string>::iterator search(const string &);
	void insert(const string & key);
	void remove(const string &key);
	void print() ;

private:
	vector<string> DB;
	vector<string>::iterator it, it1, it2;


};


#endif // !VLIST



/************************************************************************************************************************
File Name: bst.h
Name: Luis Gustavo Grubert Valensuela Z#:23351882 lvalensuela2015@fau.edu
Course: Data Struct/Algorithm (COP3530-003)
Professor: Dr. Lofton Bullard
Due Date:04/24/2017             Due Time: 11:30PM
Total Points: 25
Assignment Number Unit 11-12 - Programming Assingment
Last Changed: 04/24/2017

Description:
In this assignment a class bst will be implemented.
This class will have a tree structure composed by nodes from the class treenode.
/************************************************************************************************************************/

#pragma once
#ifndef BST
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

class treenode
{
public:
	string county_name;
	double population_size;
	treenode *lchild, *rchild;
};

class bst
{
public:
	bst();
	~bst();
	bool empty();
	//void insert(string item);
	void insert(const string & item, const double & population);
	void insert(treenode * &, string item, double pupulation);
	void del_name(string item);
	void del_name(treenode * & loc_ptr, string item);
	treenode * search_tree(treenode *, string item);
	treenode * search_tree(string item);
	treenode * inorder_succ(treenode *);
	treenode * parent();
	void graph(ostream & out) const;
	void graphAux(ostream & out, int indent, treenode * subtreeRoot) const;
	

	bool isNumber(string s);

	void split(const std::string& str, std::vector<std::string>& v);

	void population_ranges(const double& min_size, const double & max_size); //prints all county names //o the screen with a population size between min_size and max_size.
	void bst::population_ranges(treenode * loc_ptr, const double & min_size, const double & max_size); //prints all county names //o the screen with a population size between min_size and max_size.
	void sorted_info();//prints each county record to a file called “county_info.txt” sorted by county //name”.

	void print_tree();
	//void print_tree(treenode *);
	void print_tree(treenode * loc_ptr, ostream & out); 
	int Count_Nodes_with_Two_Children(treenode *loc_ptr);
	int Count_Nodes_with_Two_Children();

private:
	treenode *root;
	vector<string> v;
	vector<string>::iterator it;
	int countNodes = 0;

};
#endif // !BST

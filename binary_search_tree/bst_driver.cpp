/************************************************************************************************************************
File Name: bst_driver.cpp
Name: Luis Gustavo Grubert Valensuela Z#:23351882 lvalensuela2015@fau.edu
Course: Data Struct/Algorithm (COP3530-003)
Professor: Dr. Lofton Bullard
Due Date:04/24/2017             Due Time: 11:30PM
Total Points: 25
Assignment Number Unit 11-12 - Programming Assingment
Last Changed: 04/24/2017

Description:
In this assignment a class bst will be implemented.
This class will have a tree structure.
/************************************************************************************************************************/
#include "bst.h"

int main()
{

	cout << "Test1: default constructor\n";
	bst  myTree;

	myTree.print_tree();
	cout << "End Test1\n\n";

	cout << "Test2:insert\n\n";
	myTree.insert("new-county", 234658);
	myTree.insert("j", 234658);
	myTree.print_tree();
	cout << "End Test2\n\n";

	cout << "Test3: population_ranges\n";
	myTree.population_ranges(0, 50000);
	cout << "End Test3\n\n";

	cout << "Test3: population_ranges\n";
	myTree.population_ranges(0, 10000);
	cout << "End Test3.2\n\n";

	cout << "Test4: del_name\n";
	myTree.del_name("Miami-Dade");
	cout << "End Test4\n/n";

	cout << "Test4: del_name\n";
	myTree.del_name("new-county");
	cout << "End Test4\n/n";

	cout << "Test5: sorted_info\n";
	myTree.sorted_info();
	cout << "End Test5\n\n";


	myTree.graph(cout);
	
	cout << "Counting tres " << endl;
	cout << myTree.Count_Nodes_with_Two_Children()<< endl;
	cout << "Counting tres FINAL" << endl;

	cout << "Counting tres " << endl;
	cout << myTree.Count_Nodes_with_Two_Children() << endl;
	cout << "Counting tres FINAL" << endl;

	return 0;
}


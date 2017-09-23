/************************************************************************************************************************
File Name: bst.cpp
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


#include "bst.h";
#include <fstream>;
//*************************************************************************************
//Name: bst() (Default Constructor)
//Precondition: None
//Postcondition: Reads the file "county_data.txt" and populates the tree with
//               county names and population size.
//Description:   Reads the file "county_data.txt" and populates the tree with
//               county names and population size.
//*************************************************************************************
bst::bst()
{
	string countryName;
	double popSize;
	root = 0;
	fstream fin;
	fin.open("county_data.txt");
	if (!fin.fail())
	{
		while (!fin.eof()) {
			getline(fin, countryName);
			split(countryName, v);
		}
	}
	else
	{
		cout << "Error while trying to open file 'county_data.txt'";
	}

	//erase empty values from vector v
	for (it = v.begin(); it != v.end(); it++)
	{
		if (*it == "")
		{
			it = v.erase(it);
		}
		else if (isNumber(*it))
		{

		}
		else
		{
			if (!isNumber(*(it + 1)))
			{
				if (it != v.end())
				{
					*it = *it + " " + *(it + 1);
					it = v.erase(it + 1);
				}
			}
		}
	}

	cout << "Reading File Completed" << endl;

	for (it = v.begin(); it != v.end(); it++)
	{
		if (!isNumber(*it))
		{
			countryName = *it;
			popSize = stod(*(it + 1));
			insert(countryName, popSize);
			//cout << "countryname: " << *it << endl;
		}
	}
}


//*************************************************************************************
//Name: isNumber() Auxiliary Function
//Precondition: A String has been provided.
//Postcondition: checks if a string is a number of not, returning true or false.
//Description:   checks if a string is a number of not, returning true or false.
//
//*************************************************************************************
bool bst::isNumber(string s)
{
	return !s.empty() && find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c); }) == s.end();
	/*if (isdigit(atoi(line.c_str()))) return true;
	return false;*/
}

//*************************************************************************************
//Name: split() Auxiliary Function
//Precondition: A string and a vector has been provided.
//Postcondition: Splits a string using space as the delimiter into a string vector.
//Description:   Splits a string using space as the delimiter into a string vector.
//
//*************************************************************************************
void bst::split(const std::string& str, std::vector<std::string>& v) {
	stringstream ss(str);
	ss >> noskipws;
	string field;
	char ws_delim;
	while (1) {
		if (ss >> field)
			v.push_back(field);
		else if (ss.eof())
			break;
		else
			v.push_back(std::string());
		ss.clear();
		ss >> ws_delim;
	}
}

//*************************************************************************************
//Name: isEmpty()
//Precondition: a tree structure has been created.
//Postcondition: Returns true if the tree is empty.
//Description:   Returns true if the tree is empty.
//
//*************************************************************************************
bool bst::empty()
{
	return (root == 0);
}


//*************************************************************************************
//Name: insert(const string & item, const double & population)
//Precondition: a tree structure has been created.
//Postcondition: Inserts a new node to the tree, alphabetically sorted.
//Description:   Inserts a new node to the tree, alphabetically sorted.
//
//*************************************************************************************
void bst::insert(const string & item, const double & population)
{
	insert(root, item, population);
}
//*************************************************************************************
//Name: insert(treenode * & loc_ptr, string item, double population) Auxiliary Function
//Precondition: a tree structure has been created.
//Postcondition: Inserts a new node to the tree, alphabetically sorted.
//Description:   Inserts a new node to the tree, alphabetically sorted.
//
//*************************************************************************************
void bst::insert(treenode * & loc_ptr, string item, double population)
{
	if (loc_ptr == 0)
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->county_name = item;
		loc_ptr->population_size = population;
	}
	else if (loc_ptr->county_name > item)
		insert(loc_ptr->lchild, item, population);
	else if (loc_ptr->county_name < item)
		insert(loc_ptr->rchild, item, population);
	else
		cout << "the item is already in the tree\n";
}

//*************************************************************************************
//Name: population_ranges(const double& min_size, const double & max_size) 
//Precondition: a tree object has been created.
//Postcondition: Print all the elements of the tree that has the population size in the range
//				 between min_size and max_size.
//Postcondition: Print all the elements of the tree that has the population size in the range
//				 between min_size and max_size.
//
//*************************************************************************************
void bst::population_ranges(const double& min_size, const double & max_size)
{
	population_ranges(root, min_size, max_size);
}

//*************************************************************************************
//Name: population_ranges(treenode * loc_ptr, const double& min_size, const double & max_size) Auxiliary Function
//Precondition: a tree object has been created.
//Postcondition: Print all the elements of the tree that has the population size in the range
//				 between min_size and max_size.
//Postcondition: Print all the elements of the tree that has the population size in the range
//				 between min_size and max_size.
//
//*************************************************************************************
void bst::population_ranges(treenode * loc_ptr, const double& min_size, const double & max_size)
{
	if (loc_ptr != 0)
	{
		population_ranges(loc_ptr->lchild, min_size, max_size);
		if (loc_ptr->population_size >= min_size && loc_ptr->population_size <= max_size)
			cout << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		population_ranges(loc_ptr->rchild, min_size, max_size);
	}

}
//*************************************************************************************
//Name: vlist::search_tree(string item)
//Precondition: a tree object has been created.
//Postcondition: Searches for a string into the tree structure.
//				 Returns the pointer to the node that the string was found.
//Description:   Searches for a string into the tree structure.
//				 Returns the pointer to the node that the string was found.
//
//*************************************************************************************
treenode * bst::search_tree(string item)
{
	return search_tree(root, item);
}

//*************************************************************************************
//Name: vlist::search_tree(treenode * loc_ptr, string item) Auxiliary Function
//Precondition: a tree object has been created.
//Postcondition: Searches for a string into the tree structure.
//				 Returns the pointer to the node that the string was found.
//Description:   Searches for a string into the tree structure.
//				 Returns the pointer to the node that the string was found.
//
//*************************************************************************************
treenode * bst::search_tree(treenode * loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item)
			return loc_ptr;
		else if (loc_ptr->county_name > item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
}

//*************************************************************************************
//Name: del(string item)
//Precondition: a tree object has been created.
//Postcondition: Removes a element from the tree if name matches the string item.
//Description:   Removes a element from the tree if name matches the string item.
//
//*************************************************************************************
void bst::del_name(string item)
{
	del_name(root, item);
}
//*************************************************************************************
//Name: del(treenode * & loc_ptr, string item) Auxiliary Function
//Precondition: a tree object has been created.
//Postcondition: Removes a element from the tree if name matches the string item.
//Description:   Removes a element from the tree if name matches the string item.
//
//*************************************************************************************
void bst::del_name(treenode * & loc_ptr, string item)
{

	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->county_name > item)
		del_name(loc_ptr->lchild, item);
	else if (loc_ptr->county_name < item)
		del_name(loc_ptr->rchild, item);

	else
	{
		treenode * ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}

}
//*************************************************************************************
//Name: inorder_succ(treenode * loc_ptr) Auxiliary Function
//Precondition: a tree object has been created.
//Postcondition: creates a pointer to iterate through out the tree. Used by del_name function.
//Description:   creates a pointer to iterate through out the tree. Used by del_name function.
//
//*************************************************************************************
treenode * bst::inorder_succ(treenode * loc_ptr)
{

	treenode *ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}

//*************************************************************************************
//Name: print_tree()
//Precondition: a tree object has been created.
//Postcondition: Print all the elements of the tree, one per line.
//Description:   Print all the elements of the tree, one per line..
//
//*************************************************************************************
void bst::print_tree()
{
	print_tree(root, cout);
}
//*************************************************************************************
//Name: print_tree(treenode * loc_ptr, ostream & out) Auxiliary Function
//Precondition: a tree object has been created.
//Postcondition: Print all the elements of the tree, one per line.
//Description:   Print all the elements of the tree, one per line..
//
//*************************************************************************************
void bst::print_tree(treenode * loc_ptr, ostream & out)
{
	if (loc_ptr != 0)
	{

		print_tree(loc_ptr->lchild, out);
		out << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		print_tree(loc_ptr->rchild, out);
	}
}

void bst::graph(ostream & out) const
{
	graphAux(out, 0, root);
}

void bst::graphAux(ostream & out, int indent, treenode * subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		graphAux(out, indent + 15, subtreeRoot->rchild);
		out << setw(indent) << " " << subtreeRoot->county_name << "-" << subtreeRoot->population_size << endl;
		graphAux(out, indent + 15, subtreeRoot->lchild);
	}
}
void bst::sorted_info()
{
	ofstream outFile;
	outFile.open("county_info.txt");
	if (!outFile.fail())
	{
		print_tree(root, outFile);
	}
	else
	{
		cout << "Failure to open the outputfile named 'county_info.txt'" << endl;
	}
}

int bst::Count_Nodes_with_Two_Children() {
	countNodes = 0;
	return Count_Nodes_with_Two_Children(root);
}

int bst::Count_Nodes_with_Two_Children(treenode *loc_ptr)
{
	if (loc_ptr != 0)
	{
		Count_Nodes_with_Two_Children(loc_ptr->lchild);
		if (loc_ptr->rchild != 0 && loc_ptr->lchild != 0)
			countNodes++;
		Count_Nodes_with_Two_Children(loc_ptr->rchild);
	}

	return countNodes;
}


bst::~bst()
{
	while (root != 0)
	{
		del_name(root->county_name);
	}
}


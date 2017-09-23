
/************************************************************************************************************************
File Name: infix.cpp
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


int main()
{
	//stack S;

	//S.push("hello class");
	//S.push("The test was fun");
	//S.push("We should do it again soon ...");
	//S.push("Good bye all");

	//S.print();

	//cout << endl << endl;
	//S.print();
	//cout << endl << endl;
	//S.pop();
	//S.print();
	//cout << endl << endl;

	//stack E = S;

	//stack Guti;
	//cout << "---______---" << endl;
	//Guti = E;
	//Guti.print();
	//cout << "---______---" << endl;

	//E.print();
	//cout << endl << endl;
	//S.print();

	string continueLoop = "y";

	do
	{
		string escapeLineBreak;
		string postFixExp;
		cout << "Please, Insert a postfix expresion " << endl;
		getline(cin, postFixExp);

		cout << "You entered the following expresion: " << endl;
		cout << postFixExp << endl;

		stack infixSt;
		string temp;
		string leftOperand, rightOperand;
		string expression = "";
		string errorMessage = "";
		for (int i = 0; i < postFixExp.length(); i++)
		{
			if (postFixExp[i] != '+' && postFixExp[i] != '-' && postFixExp[i] != '/' && postFixExp[i] != '*')
			{
				temp = postFixExp[i];
				if (postFixExp.length() == 1)
				{
					expression = "( " + temp + " )";
					break;
				}
				if (postFixExp[i] != ' ')
				{
					infixSt.push(temp);
				}
			}
			else
			{
				temp = postFixExp[i];

				if (!infixSt.isEmpty())
				{
					rightOperand = infixSt.top();
					infixSt.pop();
				}

				if (!infixSt.isEmpty())
				{
					leftOperand = infixSt.top();
					infixSt.pop();
				}else
				{
					errorMessage = "Too many operators and not enougth operands.";
				}
				expression = "(" + leftOperand + " " + temp + " " + rightOperand + ")";
				infixSt.push(expression);
			}

		}
		//remove the complete expression from the stack
		if (!infixSt.isEmpty())
		{
			infixSt.pop();
		}

		if (!infixSt.isEmpty())
		{
			errorMessage = "Too many operands and not enougth operators.";
		}
		if (errorMessage != "")
		{
			cout << "Error: " + errorMessage << endl;
		}
		else
		{
			cout << "Infix Expression: " << expression << endl;
		}

		cout << "Do you want do another conversion (y or n)";
		cin >> continueLoop;
		getline(cin, escapeLineBreak);

	} while (continueLoop == "y");
	return 0;
}

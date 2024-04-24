// program written by Tommy Trinh
// April 23
// this program keeps track of a cell phone store's inventory and
// can print out receipts
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>
#include <deque>
#include "Cellphone.h"
#include "Customer.h"
using namespace std;

// global constants
const char invFile[] = "c:\\test\\cellphone.txt";	// inventory file holding cellphone data
const int
MAX_PHONES=22,		// max phones in inventory
BUY_PHONE = 1,		// buy phone menu choice
CHECK_OUT = 2,		// check out menu choice
QUIT = 3;			// quit menu choice

// function prototypes
void header();	// shows program info
// creates a stack for keeping inventory
void createStack(stack<Cellphone, vector<Cellphone>>&);
// creates a customer and adds info to the queue
void buyPhone(stack<Cellphone, vector<Cellphone>>&, deque<Customer>&);
// checks out customers one at a time
void checkOut(stack<Cellphone, vector<Cellphone>>&, deque<Customer>&);
bool menuValid(int);

int main()
{
	// local variables
	stack<Cellphone, vector<Cellphone>> cellStack;
	deque<Customer> cust;
	string input;
	int menuChoice;

	// call header
	header();

	// populate the stack
	createStack(cellStack);

	// display menu with switch cases for user input
	do
	{
		do
		{
			cout << endl << BUY_PHONE << ". Buy phone\n"
				<< CHECK_OUT << ". Check out\n"
				<< QUIT << ". Quit Program\n"
				<< "Enter menu choice: ";
			getline(cin, input);
		} while (menuValid(stoi(input)));
		menuChoice = stoi(input);

		switch (menuChoice)
		{
		case BUY_PHONE:
		{
			buyPhone(cellStack, cust);
			break;
		}
		case CHECK_OUT:
		{
			checkOut(cellStack, cust);
			break;
		}
		case QUIT:
		{
			if (!cust.empty())
			{
				cout << "Error - there are still customers in the checkout queue!\n"
					<< "Please return to main menu and check out all of the customers!\n\n";
				menuChoice = BUY_PHONE;
			}
			break;
		}
		default:
		{
			cout << "something went wrong.\n\n";
		}
		}
	} while (menuChoice != QUIT);

	// at the end of the program, print a thank you message
	cout << "\nThank you for using our program today.\n";
	return 0;
}



// Function open file, if it can't open then give an error. If it can open, then
// loop through the file getting two lines at a time and putting the lines
// into a temp object. After the temp object is made, then push the object into the
// stack. Close the file afterwards.
void createStack(stack<Cellphone, vector<Cellphone>>& cellStack)
{
	// create temporary variables for holding file info
	Cellphone temp;
	string tempId,
		tempNum;

	// open file for reading
	ifstream iFile(invFile);
	// if couldn't open, give error
	if (iFile.fail())
	{
		cout << "Error opening file.\n";
	}
	else
	{
		while (!iFile.eof())
		{
			getline(iFile, tempId);
			getline(iFile, tempNum);
			Cellphone temp(tempId, tempNum);
			cellStack.push(temp);
		}
	}
	// close file
	iFile.close();
}

// Buy phone menu option. Lets users enter a name and number of phones to buy.
// Validates number of phones is between 1 and 6. Uses a static counter to keep
// track of total phones sold. If total sold and requested is greater than total stock,
// give an error. At the end, push back the deque with a new customer
void buyPhone(stack<Cellphone, vector<Cellphone>>& cellStack, deque<Customer>& custDeque)
{
	string custName,			// temp string to hold customer name input
		tempNum;				// temp string to hold phone bought input
	int num;					// temp variable to hold phones bought
	static int counter = 0;		// counter variable counts num phones sold 
	if (cellStack.empty())
	{
		cout << "Error - inventory empty, returning to menu\n\n";
		return;
	}
	else
	{
		cout << "Please enter in the customer name: ";
		getline(cin, custName);
		do
		{
			if (MAX_PHONES - counter > MAX_PURCHASE)
				cout << "Please enter in the number of phones to purchase (" << MIN_PURCHASE
				<< " - " << (MAX_PURCHASE) << "): ";
			else
				cout << "Please enter in the number of phones to purchase (" << MIN_PURCHASE
				<< " - " << (MAX_PHONES - counter) << "): ";
			getline(cin, tempNum);
			num = stoi(tempNum);
			if ((counter + num) > MAX_PHONES)
			{
				cout << "Error - there are only " << (MAX_PHONES - counter)
					<< " cellphones left. Please reenter.\n\n";
			}
			if (num<MIN_PURCHASE || num>MAX_PURCHASE)
			{
				cout << "Error - you can only purchase 1 - " << (MAX_PHONES - counter)
					<< " phones.Please reenter!\n\n";
			}
		} while ((counter + num) > MAX_PHONES || num<MIN_PURCHASE || num>MAX_PURCHASE);
		counter += num;
		Customer temp(custName, num);
		custDeque.push_back(temp);
	}
}

// Check out customers one at a time. If there are no customers, return to menu.
// Use front() to print out the name, number of phones bought, and amount due
// for the front customer. Then use the number of phones bought to loop
// through and pop cellphones from the stack
void checkOut(stack<Cellphone, vector<Cellphone>>& cellStack, deque<Customer>& custDeque)
{
	if (custDeque.empty())
	{
		cout << "There are no customers to checkout! Returning to menu...\n";
		return;
	}
	else
	{
		cout << left << setw(16) << endl << "Customer Receipt" << ": \n";
		cout << left << setw(16) << "Customer name" << ": " << custDeque.front().getCName() << endl;
		cout << left << setw(16) << "Number phones" << ": " << custDeque.front().getPurchaseNum() << endl;
		cout << setprecision(2) << fixed << showpoint;
		cout << left << setw(16) << "Total amount due" << ": $" << custDeque.front().getTotalCost() << endl << endl;
		cout << noshowpoint;
		cout << "Phone(s) id and number:\n";
		for (int i = 0; i < custDeque.front().getPurchaseNum(); i++)
		{
			cout << "Id number: " << cellStack.top().getIdNum() << "\t"
				<< "Phone number: " << cellStack.top().getPhoneNum() << endl;
			cellStack.pop();
		}
		custDeque.pop_front();
	}
}

// prints program info to user
void header()
{
	cout << "\t\t\t\tCMSY 171 Lab 8\n"
		<< "Copyright 2024 - Howard Community College All rights reserved; "
		<< "Unauthorized duplication prohibited.\n\n"
		<< "Welcome to CMSY-171 Cell Phone Purchase Program\n\n";
}

// menu validation, returns true and continues looping if invalid
// returns false if valid and leaves loop
bool menuValid(int choice)
{
	if (choice<BUY_PHONE || choice>QUIT)
	{
		cout << "Invalid choice! Try again:\n";
		return true;
	}
	return false;
}
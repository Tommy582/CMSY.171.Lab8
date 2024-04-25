#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Cellphone.h"
using namespace std;

// global constants
const int
MIN_PURCHASE = 1,			// minimum purchase amount
MAX_PURCHASE = 6;			// maximum purchase amount
const double
PHONE_PRICE = 199.99,		// cost of a phone
SALES_TAX = 1.06;			// sales tax

class Customer
{
private:
	string cName;			// holds customer's name
	int purchaseNum;		// holds number of phones purchased
	double totalCost;		// total cost of order
	Cellphone phoneArray[MAX_PURCHASE];
public:
	Customer();				// default constructor
	Customer(string custName, int num,Cellphone cellArray[]);	// constructor that takes two arguments

	// accessor functions
	string getCName() const;
	int getPurchaseNum() const;
	double getTotalCost() const;
	Cellphone getPhoneArray();

	// mutator functions
	void setCName(string);
	void setPurchaseNum(int);
	void setPhoneArray(int,Cellphone[]);

	double calcTotalCost(int);	// calculate total cost


};
#endif
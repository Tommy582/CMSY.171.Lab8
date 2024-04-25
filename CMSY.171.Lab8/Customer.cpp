#include "Customer.h"

// default constructor
Customer::Customer()
{
	cName = "none";
	purchaseNum = 0;
	totalCost = 0.0; 
	phoneArray[1];
}

// constructor that takes name and number of phones bought
Customer::Customer(string custName, int num, Cellphone cellArray[])
{
	cName = custName;
	purchaseNum = num;
	totalCost = calcTotalCost(num);
	setPhoneArray(num, cellArray);
}

// accessor function for customer name
string Customer::getCName() const
{
	return cName;
}

// accessor function for number of phones purchased
int Customer::getPurchaseNum() const
{
	return purchaseNum;
}

// accessor function for total cost
double Customer::getTotalCost() const
{
	return totalCost;
}

Cellphone Customer::getPhoneArray()
{
	return *phoneArray;
}

// mutator function for customer name
void Customer::setCName(string name)
{
	cName = name;
}

// mutator function for number of phones purchased
void Customer::setPurchaseNum(int num)
{
	purchaseNum = num;
}

// mutator function for cellphone array
void Customer::setPhoneArray(int num,Cellphone cellArray[])
{
	for (int i = 0; i < num; i++)
	{
		phoneArray[i] = cellArray[i];
	}
}

// calculates total cost
double Customer::calcTotalCost(int num)
{
	return ((num * PHONE_PRICE) * SALES_TAX);
}
#include "Customer.h"

Customer::Customer()
{
	cName = "none";
	purchaseNum = 0;
	totalCost = 0.0; 
	phoneArray = new Cellphone[1];
}

Customer::Customer(string custName, int num)
{
	cName = custName;
	purchaseNum = num;
	totalCost = calcTotalCost(num);
	phoneArray = new Cellphone[purchaseNum];
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
void Customer::setPhoneArray(int num)
{
	phoneArray = new Cellphone[num];
}

// calculates total cost
double Customer::calcTotalCost(int num)
{
	return ((num * PHONE_PRICE) * SALES_TAX);
}
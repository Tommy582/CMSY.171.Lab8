#include "Cellphone.h"

// default constructor, sets both private variables to none
Cellphone::Cellphone()
{
	idNum = "none";
	phoneNum = "none";
}

// constructor that takes two arguments, idNum and phoneNum
Cellphone::Cellphone(string id, string phone)
{
	idNum = id;
	phoneNum = phone;
}

// accessor function returns idNum
string Cellphone::getIdNum() const
{
	return idNum;
}

// accessor function returns phoneNum
string Cellphone::getPhoneNum() const
{
	return phoneNum;
}

// mutator function sets idNum
void Cellphone::setIdNum(string id)
{
	idNum = id;
}

// mutator function sets phoneNum
void Cellphone::setPhoneNum(string phone)
{
	phoneNum = phone;
}
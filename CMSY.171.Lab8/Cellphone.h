#ifndef CELLPHONE_H
#define CELLPHONE_H
#include <string>
using namespace std;

class Cellphone
{
private:
	string idNum,			// cell phone id number
		phoneNum;			// cell phone number
public:
	// default constructor
	Cellphone();

	// constructor that takes idNum and phoneNum
	Cellphone(string, string);

	// accessor functions
	string getIdNum() const;
	string getPhoneNum() const;

	// mutator functions
	void setIdNum(string);
	void setPhoneNum(string);
};
#endif
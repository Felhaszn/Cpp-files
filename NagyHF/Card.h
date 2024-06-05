#include <iostream>
#include "Date.h"

#ifndef CARD_H
#define CARD_H

class Card{
private:
	std::string cardNumber;
	std::string cardOwner;
	int cvc;
	Date expDate;
public:
	Card() : cvc(0) {};

	void setNumber(std::string num);

	void setOwner(std::string owner);

	void setCVC(int num);

	void setExpDate(Date d);

	std::string getNumber();

	std::string getOwner();

	int getCVC();

	Date getExpDate();

	~Card() {};
};

#endif

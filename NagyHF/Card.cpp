#include "Card.h"

void Card::setNumber(std::string num) {
	this->cardNumber = num;
}

void Card::setOwner(std::string owner) {
	this->cardOwner = owner;
}

void Card::setCVC(int num) {
	this->cvc = num;
}

void Card::setExpDate(Date d) {
	this->expDate = d;
}

std::string Card::getNumber() { return this->cardNumber; }

std::string Card::getOwner() { return this->cardOwner; }

int Card::getCVC() { return this->cvc; }

Date Card::getExpDate() { return this->expDate; }
#include <fstream>
#include <iostream>

#include "Date.h"
#include "bigint.h"
#include "Card.h"
#include "RSA.h"
#include "memtrace.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account : public RSA{
private:
	int balance;
	std::string PasswordHash;
	bigint publicKey;
	bigint privateKey;
	Card accountCard;
	std::string accountNumber;
	std::string accountOwner;
	Date birthDate;
public:
	Account() :balance(0) {};

	//Az alapvetõ adatokat beírja az osztályba és a fájlba
	Account(std::string Owner, Date bd, std::string pass) :balance(0), birthDate(bd) { 
		setAccountOwner(Owner);
		publicKey = generatePublicKey();
		privateKey = generatePrivateKey();

		accountNumber = std::to_string(rand() % (10000000 - 99999999) + 10000000) + '-' + 
			std::to_string(rand() % (10000000 - 99999999) + 10000000) + '-' + 
			std::to_string(rand() % (10000000 - 99999999) + 10000000);

		createPasswordHash(pass);

		std::ofstream file;
		std::string line;

		file.open("accounts.txt");
		
		line = Owner + ' ' + std::to_string(balance) + ' ' + publicKey.get() + ' ' + accountNumber + ' ' + PasswordHash;
		
		file << line << std::endl;
		
		file.close();
		
	};

	bigint getPublicKey();

	std::string getAccountNumber();

	std::string getAccountOwner();

	int getBalance() { return balance; }

	std::string getPasswordHash() { return PasswordHash; }

	void setPublicKey(int pk);

	void setAccountNumber(std::string an);

	void setAccountOwner(std::string ao);

	void setBalance(int b) { balance = b; }

	void setPasswordHash(std::string hash) { PasswordHash = hash; }

	void setCard(Card c) { accountCard = c; }

	bool authorizePassword();

	void createPasswordHash(std::string password);

	bool authorizeName();

	void makeTransaction(int amount);

	~Account() {};
};


#endif
#include "Account.h"

bigint Account::getPublicKey() {
	return publicKey;
}

std::string Account::getAccountNumber() {
	return accountNumber;
}

std::string Account::getAccountOwner() {
	return accountOwner;
}

void Account::setPublicKey(int pk) {
	publicKey = pk;
}

void Account::setAccountNumber(std::string an) {
	accountNumber = an;
}

void Account::setAccountOwner(std::string ao) {
	accountOwner = ao;
}

bool Account::authorizeName() {
	std::string username;
	std::cout << "Your name (without space): ";
	std::cin >> username;
	if (username == this->accountOwner) {
		return true;
	}

	return false;
}

bool Account::authorizePassword() {
	std::cout << "Password: ";

	std::string password;

	std::cin >> password;

	std::hash<std::string> hasher;

	size_t hashValue = hasher(password);

	std::string hashString = std::to_string(hashValue);

	if(hashString == PasswordHash)
		return true;
	return false;
}

void Account::createPasswordHash(std::string password) {
	std::hash<std::string> hasher;

	size_t hashValue = hasher(password);

	std::string hashString = std::to_string(hashValue);

	PasswordHash = hashString;
}

void Account::makeTransaction(int amount) {
	balance -= amount;
	if (balance < 0) balance = 0;
}

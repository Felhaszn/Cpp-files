#include "Layout.h"
#include "Date.h"

void registerScreen() {
	
}

void loginScreen() {
	for (int i = 0; i < 38; i++) {
		std::cout << '*';
	}
	std::cout << '\n';

	std::cout << "* Welcome to Banking Simulator 2000! *" << std::endl;

	for (int i = 0; i < 38; i++) {
		std::cout << '*';
	}
	std::cout << '\n' << std::endl;

	std::cout << "Please login, or create an account!" << std::endl;
}

void mainMenu() {
	std::cout <<
		"1. Transfer\n" <<
		"2. Create card\n" <<
		"3. Change password\n" <<
		"4. Your account information\n" <<
		"5. Logout" << std::endl;
}

void Transfer(Account a) {
	int amount;
	std::cout << "How much do you want to send: ";
	std::cin >> amount;
	a.makeTransaction(amount);
	std::cout << "Money sent!" << std::endl;
}

//Egy számlanyitáshoz kellõ függvény, inicializálja az accountot
Account createAccount() {
	std::string owner;
	std::string password;
	int bd, bm, by;

	std::cout << "Who is the owner of the account?(without spaces) ";
	std::cin >> owner;

	std::cout << "Enter a password(4 - 16 characters): ";
	std::cin >> password;

	while (password.length() > 16) {
		std::cout << "Too long, enter a password between 4 - 16 characters: ";
		std::cin >> password;
	}
	while (password.length() < 4) {
		std::cout << "Too short, enter a password between 4 - 16 characters: ";
		std::cin >> password;
	}

	std::cout << "Enter your day of birth: ";
	std::cin >> bd;
	std::cout << "Enter your month of birth: ";
	std::cin >> bm;
	std::cout << "Enter your year of birth: ";
	std::cin >> by;
	Date birth;
	birth.setDay(bd);
	birth.setMonth(bm);
	birth.setYear(by);

	Account acc(owner, birth, password);
	std::cout << "Account has been created!" << std::endl;
	return acc;
}

void createCard(Account a) {
	Card card;
	Date date;

	date.setYear(2027);
	date.setMonth(5);
	date.setDay(1);

	card.setNumber(std::to_string(rand() % (10000000 - 99999999) + 10000000) + '-' +
		std::to_string(rand() % (10000000 - 99999999) + 10000000) + '-' +
		std::to_string(rand() % (10000000 - 99999999) + 10000000));
	card.setCVC(rand() % (100 - 1000) + 100);
	card.setExpDate(date);
	card.setOwner(a.getAccountOwner());

	a.setCard(card);
	std::cout << "Card has been set!" << std::endl;
}

void changePassword(Account a) {
	std::string newPass;
	std::cout << "New password: ";
	std::cin >> newPass;

	a.createPasswordHash(newPass);

	std::ofstream file; std::string line;
	file.open("accounts.txt");

	line = a.getAccountOwner() + ' ' + std::to_string(a.getBalance()) + ' ' + a.getPublicKey().get() + ' ' + a.getAccountNumber() + ' ' + a.getPasswordHash();

	file << line << std::endl;

	file.close();

	std::cout << "New password has been set." << std::endl;
}

void info(Account a) {
	std::cout << "Owner: " << a.getAccountOwner() <<std::endl;
	std::cout << "Number: " << a.getAccountNumber() << std::endl;
	std::cout << "Balance: " << a.getBalance() << std::endl;
}
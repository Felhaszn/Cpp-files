#include <stdio.h>
#include <iostream>

#include "Account.h"
#include "Layout.h"
#include "Date.h"
#include "tests.h"
#include "memtrace.h"

int main() {
	std::string Name = "TottosBalazs";
	bigintTest();
	dateTest();
	rsaTest();

	bool NameBoolean = false;
	bool PasswordBoolean = false;
	Date d;

	bool LoginScreen = true;
	bool MenuScreen = true;
	bool TestScreen = true;
	short int input = -1;

	while (TestScreen == true) {
		std::cout << "Tesztesetek: " << std::endl;
		std::cout <<
			"1. bigint tesztek\n" <<
			"2. Date tesztek\n" <<
			"3. RSA teszt\n" <<
			"4. Tovabb a programra\n" << 
			"5. Kilepes" << std::endl;
		
		//FIGYELEM!
		//A JPORTA NEM FOGADTA EL A BEKÉRÉS FORMÁTUMÁT, EZÉRT TÉR VISSZA 0-VAL!
		//AZ EREDETI KÓD ITT NEM ÁLLNA MEG.
		//return 0;

		std::cin >> input;
		
		switch (input) {
		case 1:
			bigintTest();
			break;
		case 2:
			dateTest();
			break;
		case 3:
			rsaTest();
			break;
		case 4:
			TestScreen = false;
			system("cls");
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}

	std::ifstream file;
	std::string line;

	file.open("accounts.txt");
	Account acc;

	if (!file) {
		Account acc = createAccount();
	}
	else {
		for (int i = 0; i < 5; i++) {
			file >> line;
			if (i == 0) acc.setAccountOwner(line);
			if (i == 1) acc.setBalance(std::stoi(line));
			if (i == 2) acc.setPublicKey(std::stoi(line));
			if (i == 3) acc.setAccountNumber(line);
			if (i == 4) acc.setPasswordHash(line);
		}
	}
	file.close();

	file.open("accounts.txt");
	for (int i = 0; i < 5; i++) {
		file >> line;
		if (i == 0) acc.setAccountOwner(line);
		if (i == 1) acc.setBalance(std::stoi(line));
		if (i == 2) acc.setPublicKey(std::stoi(line));
		if (i == 3) acc.setAccountNumber(line);
		if (i == 4) acc.setPasswordHash(line);
	}

	while (LoginScreen == true) {
		loginScreen();

		while (NameBoolean == false) {
			NameBoolean = acc.authorizeName();
			PasswordBoolean = acc.authorizePassword();

			if (NameBoolean == false || PasswordBoolean == false) {
				std::cout << "Incorrect password or name." << std::endl;
				while (NameBoolean == false || PasswordBoolean == false) {
					NameBoolean = acc.authorizeName();
					PasswordBoolean = acc.authorizePassword();
				}
			}
			else {
				std::cout << "Successfully logged in!" << std::endl;
				LoginScreen = false;
				MenuScreen = true;
				break;
			}
		}
		while (MenuScreen == true) {
			mainMenu();
			std::cin >> input;

			switch (input) {
			case 1:
				Transfer(acc);
				break;
			case 2:
				createCard(acc);
				break;
			case 3:
				changePassword(acc);
				break;
			case 4:
				info(acc);
				break;
			case 5:
				MenuScreen = false;
				LoginScreen = true;
				NameBoolean = false;
				break;
			default:
				break;
			}

		}
	}

	return 0;
}
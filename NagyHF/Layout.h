#include <iostream>
#include <ctime>
#include "Account.h"

#ifndef LAYOUT_H
#define LAYOUT_H

void registerScreen();

void loginScreen();

void mainMenu();

void Transfer(Account a);

Account createAccount();

void createCard(Account a);

void changePassword(Account a);

void info(Account a);

#endif
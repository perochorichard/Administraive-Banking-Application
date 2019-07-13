#include <iostream>
#include "UserAccount.h"
#include "AccountList.h"
#include "Utility.h"

AccountList* accounts = new AccountList();
int main()
{
	std::system("CLS");
	std::cout << "make a selection\n"
		"1. Create new account\n"
		"2. find account\n"
		"3. Login to account\n"
		"4. remove account\n"
		"5. display current accounts\n"
		"6. display accounts on file\n"
		"7. save file\n"
		"8. sort\n"
		"9. generate accounts\n"
		"a. exit\n"<< std::endl;

	std::string selection;
	std::cin >> selection;

	switch (selection.at(0)) {
	case '1': {
		std::string username, clientName, password;
		double balance;

		std::cout << "Enter client username: ";
		std::cin >> username;
		if (accounts->find(username) != NULL) {
			std::cout << "username already taken" << std::endl;
			std::system("PAUSE");
			main();
		}

		std::cout << "Enter client name: ";
		std::cin >> clientName;
		std::cout << "Enter temporary password: ";
		std::cin >> password;
		std::cout << "Enter client balance: ";
		std::cin >> balance;

		UserAccount* newAccount = new UserAccount(username, clientName, password, balance);
		if (accounts->add(newAccount)) {
			std::cout << "account created successfully." << std::endl;
			std::system("PAUSE");
			break;
		}
		std::cout << "unsuccessful account creation" << std::endl;
		std::system("PAUSE");
		break;
	}
	case '2': {
		std::cout << "Find account\nEnter username: ";
		std::string username;
		std::cin >> username;
		Node* accountNode = accounts->find(username);
		if (accountNode == NULL) {
			std::cout << "account could not be found.\n";
		}
		else {
			std::cout << Utility::format(accountNode->account) << std::endl;
		}
		std::system("PAUSE");
		break;
	}
	case '3': {
		std::cout << "Enter Username: ";
		std::string username, password;
		std::cin >> username;
		std::cout << "Enter Password: ";
		std::cin >> password;
		Node* accountNode = accounts->find(username);
		if (accountNode == NULL) {
			std::cout << "account could not be found.\n";
			std::system("PAUSE");
			break;
		}
		UserAccount* account = accountNode->account;
		if (account->getPassword().compare(password) != 0) {
			std::cout << "incorrect password.\n";
			std::system("PAUSE");
			break;
		}
		std::string option;
		std::cout << Utility::format(account) << std::endl;
		std::cout << "1. deposit\n2.widthdraw\n3.change password\n4.exit\n";
		std::cin >> option;
		double amount;
		switch (option.at(0)) {
		case '1': {
			cout << "Enter amount: ";
			cin >> amount;
			account->deposit(amount);
			break;
		}
		case '2': {
			cout << "Enter amount: ";
			cin >> amount;
			account->deposit(-amount);
			break;
		}
		case '3': {
			std::string password;
			std::cout << "enter new password: ";
			std::cin >> password;
			account->setPassword(password);
			std::cout << "password saved.\n";
			std::system("PAUSE");
			break;
		}
		default:
			break;
		}
		break;
	}
	case '4': {
		std::cout << "Deleting Account\n";
		std::cout << "Enter username: ";
		std::string account;
		std::cin >> account;
		std::cout << "delete " + account + "? (y/n): ";
		std::string answer;
		std::cin >> answer;
		if (answer.compare("y") == 0) {
			if (accounts->remove(account)) {
				std::cout << "successully deleted.\n";
			}
			else {
				std::cout << "account could not be found.\n";
			}
		}
		else {
			std::cout << "action cancelled.\n";
		}
		std::system("PAUSE");
		break;
	}
	case '5': {
		std::cout << "------Current Accounts------" << std::endl;
		std::cout << accounts->display() << std::endl;
		std::cout << "------------------------" << std::endl;
		std::system("PAUSE");
		break;
	}
	case '6': {
		std::cout << "------Accounts File------" << std::endl;
		std::cout << accounts->retrieveFile() << std::endl;
		std::cout << "------------------------" << std::endl;
		std::system("PAUSE");
		break;
	}
	case '7': {
		accounts->save();
	}
	case '8': {
		accounts->sort();
		std::cout << "all accounts saved to file.\n";
		std::system("PAUSE");
		break;
	}
	case '9': {
		UserAccount* temp;
		std::string usernames[] = { "Jones23", "Caitlyn_", "Rodriguez0", "Patrick_98",
			"Alice_a", "Ashe_5", "Bjergsen", "Faker", "Philip99" };
		std::string names[] = {"Rosy Brazier", "Florene Eye", "Vanita Shellenberger",
			"Beth Kruse", "Ayana Dewoody", "Ronda Adamson", "Søren Bjerg", "Lee Sang-hyeok", "Aubrey Fallin"};
		std::string pwds[] = { "Zf1", "P9L", "Uql", "F7s", "otb",
			"qsz", "ez3", "ly9", "jF0" };
		for (int i = 0; i < 9; i++) {
			temp = new UserAccount(usernames[i], names[i], pwds[i], 500);
			accounts->add(temp);
		}
		std::cout << "Random accounts generated.\n";
		std::system("PAUSE");
		break;
	}
	default: {
		break;
	}
	}
	if (selection.compare("a") != 0) {
		main();
	}
}
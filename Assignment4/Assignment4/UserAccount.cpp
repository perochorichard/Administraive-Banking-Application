#include "UserAccount.h"

UserAccount::UserAccount(std::string username, std::string clientName,
	std::string password, double balance) {
	this->username = username;
	this->clientName = clientName;
	this->password = password;
	this->balance = balance;
}

bool UserAccount::setUsername(std::string username) {
	this->username = username;
	return true;
}

bool UserAccount::setClientName(std::string clientName) {
	this->clientName = clientName;
	return true;
}

bool UserAccount::setPassword(std::string passwordNew) {
	this->password = passwordNew;
	return true;
}

bool UserAccount::deposit(double amount) {
	this->balance += amount;
	return true;
}

std::string UserAccount::getUsername() {
	return this->username;
}

std::string UserAccount::getClientName() {
	return this->clientName;
}

std::string UserAccount::getPassword() {
	return this->password;
}

double UserAccount::getBalance() {
	
	return this->balance;
}